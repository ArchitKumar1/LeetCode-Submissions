// https://leetcode.com/problems/stone-game-ix

class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        cnt = [0,0,0]
        for s in stones:
            cnt[s%3] += 1
                
        @cache
        def solve(a,b,c,suma,turn):
            # print(a,b,c,suma,turn)
            ans = False
            if turn == 0:
                if suma %3 == 1:
                    #rem 1 can choose only 1 and 3;
                    if(a > 0):
                        v =  solve(a-1,b,c,(suma+1)%3,turn ^ 1)
                        if not v: ans = True
                    if(c > 0):
                        v =  solve(a,b,c-1,(suma+3)%3,turn^1)
                        if not v: ans = True

                elif suma %3 == 2:
                    #rem 2 can choose only 2 and 3;
                    if(b > 0):
                        v =  solve(a,b-1,c,(suma+2)%3,turn^1)
                        if not v: ans = True
                    if(c > 0):
                        v =  solve(a,b,c-1,(suma+3)%3,turn^1)
                        if not v: ans = True
                            
                elif suma %3 == 0:
                    if(a > 0):
                        v =  solve(a-1,b,c,(suma+1)%3,turn^1)
                        if not v: ans = True
                    if(b > 0):
                        v =  solve(a,b-1,c,(suma+2)%3,turn^1)
                        if not v: ans = True
                
            else:
                if a == 0 and b == 0 and c == 0 : ans = True
                elif suma %3 == 1:
                    #rem 1 can choose only 1 and 3;
                    if(a > 0):
                        v =  solve(a-1,b,c,(suma+1)%3,turn ^ 1)
                        if not v: ans = True
                    if(c > 0):
                        v =  solve(a,b,c-1,(suma+3)%3,turn ^ 1)
                        if not v: ans = True

                elif suma %3 == 2:
                    #rem 2 can choose only 2 and 3;
                    if(b > 0):
                        v =  solve(a,b-1,c,(suma+2)%3,turn^1)
                        if not v: ans = True
                    if(c > 0):
                        v =  solve(a,b,c-1,(suma+3)%3,turn^1)
                        if not v: ans = True
                            
                elif suma %3 == 0:
                    if(a > 0):
                        v =  solve(a-1,b,c,(suma+1)%3,turn^1)
                        if not v: ans = True
                    if(b > 0):
                        v =  solve(a,b-1,c,(suma+2)%3,turn^1)
                        if not v: ans = True
            return ans
            
        return solve(cnt[1],cnt[2],cnt[0],0,0)
        
        
        