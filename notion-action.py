import sys
from enum import Enum, auto
from typing import List, Dict, NoReturn

from github import Github
from notion_client import Client


class Status(Enum):
    ADDED = auto()
    MODIFIED = auto()
    DELETED = auto()


PLATFORM = {
    'boj': 'https://www.acmicpc.net/problem/{}',
    'programmers': 'https://programmers.co.kr/learn/courses/30/lessons/{}',
    'leetcode': 'https://leetcode.com/problems/{}/'
}

EXCEPT_FILENAME = ['notion-action.py', 'README.md', 'requirements.txt', '.github/workflows/python-package.yml']


class Problem:
    def __init__(self,
                 platform: str,
                 level: str,
                 filename: str,
                 category: List[str],
                 archive: bool,
                 github_url: str,
                 status: str) -> NoReturn:
        """
        :param platform:
        :param level:
        :param filename:
        :param category:
        :param archive:
        :param github_url:
        :param status:      added | modifed | deleted
        """
        self.name = filename.split('.')[0]
        self.platform = platform.upper() if platform == 'boj' else platform
        self.level = level
        self.category = category
        self.archive = archive
        self.github_url = github_url
        self.problem_url = PLATFORM[platform].format(self.name)
        self.status = Status[status.upper()]

    def to_query(self, database_id: str) -> Dict:
        """
        :param database_id:
        :return:
        """
        return {
            'parent': {
                'database_id': database_id
            },
            'properties': {
                # column
                'name': {
                    'title': [
                        {
                            'text': {
                                'content': self.name
                            }
                        }
                    ]
                },
                # column
                'platform': {
                    'select': {
                        'name': self.level,
                    }
                },
                # column
                'category': {
                    'multi_select': [{'name': category} for category in self.category]
                },
                # column
                'archive': {
                    'checkbox': False
                },
                # column
                'github_url': {
                    'url': self.github_url
                },
                # column
                'problem_url': {
                    'url': self.problem_url
                },
            }
        }


def file2problem(access_token: str, repo_name: str, sha: str) -> List[Problem]:
    """
    :param access_token:
    :param repo_name:
    :param sha:
    :return:
    """
    print(sha)
    g = Github(access_token)
    repo = g.get_repo(repo_name)
    commit = repo.get_commit(sha)
    problems = []
    categories = {
        'sh': 'shell',
        'sql': 'sql',
    }

    def get_category(file):
        filename_separate = file.filename.split('.')
        category = []
        if len(filename_separate) == 1:
            category.append('unknown')
        if filename_separate[1] in categories:
            category.append(categories[filename_separate[1]])
        return category

    for file in commit.files:
        if file.filename in EXCEPT_FILENAME:
            continue
        print(file.filename)
        platform, level, filename = file.filename.split('/')
        category = get_category(file)
        problems.append(Problem(platform, level, filename, category, False, file.blob_url, file.status))
    return problems


def notion_database_modify(access_token: str, database_id: str, problems: List[Problem]) -> NoReturn:
    """
    :param access_token:
    :param database_id:
    :param problems:
    :return:
    """
    notion = Client(auth=access_token)
    for p in [p for p in problems if p.status == Status.ADDED]:
        query = p.to_query(database_id)
        notion.pages.create(**query)


if __name__ == '__main__':
    # github
    github_access_token = sys.argv[1]
    repo_name = sys.argv[2]
    sha = sys.argv[3]

    # notion
    notion_access_token = sys.argv[4]
    database_id = sys.argv[5]

    problems = file2problem(github_access_token, repo_name, sha)
    notion_database_modify(notion_access_token, database_id, problems)
