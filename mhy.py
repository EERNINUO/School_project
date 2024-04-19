import random

def main(h):        #定义游戏主程序
    global alldeblood       
    global luck
    luck = 0
    for i in range(n):
        t , x = input("").split(",")
        alldeblood = 0
        if int(t) == 1:     #时来运转程序
            luck += int(x)
        elif int(t) == 2:       #幸运一掷程序
            for j in range(luck):
                deblood = random.randint(1,6)
                alldeblood += deblood
            h =h - alldeblood - int(x)
            luck = 0        #清除计数器
        else:
            print("error")
        if h <= 0:      #判断BOSS是否死亡
            return h
        else:
            print("BOSS血量:{:.0f},幸运点:{:.0f}".format(h,luck) )


n , h = input("input:").split(",")
n = eval(n)
h = eval(h)
if 1 <= h <= 10**9 or 1 <= n <= 100:        #判断输入是否合法
    main(h)
    if h <= 0:      #判断BOSS是否死亡
        print("you win")
    else:
        print("fail") 
else:
    print("error")


input()
