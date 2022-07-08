class Solution:
    def entityParser(self, text: str) -> str:
        special = [
            ('&quot;', r'"'),
            ('&apos;', r"'"),
            ('&gt;', '>'),
            ('&lt;', '<'),
            ('&frasl;', '/'),
            ('&amp;', '&'),
        ]
        
        for k, v in special:
            text = text.replace(k, v)
        return text
