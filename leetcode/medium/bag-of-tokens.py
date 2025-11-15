class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        # face down: 점수가 1이상인 경우, tokey play 시 token[i] 값을 power로 얻고, 점수 1점을 잃는다
        # face up: power가 token[i] 이상인 경우 token[i] power를 잃고 1점을 얻을 수 있다.
        # 달성 가능한 최대 점수

        # face up: 현재 power에서 가장 적은 power를 잃는 token
        # face down: face up할 수 없을 때, 가장 큰 power를 얻을 수 있는 token

        score = 0
        st, ed = 0, len(tokens) - 1
        tokens.sort()

        while st <= ed:
            if power >= tokens[st]:
                print('face up')
                power -= tokens[st]
                score += 1
                st += 1
            elif st != ed and score > 0:
                print('face down')
                power += tokens[ed]
                score -= 1
                ed -= 1
            else:
                break
            print(st, ed, power, score)
        
        return score
