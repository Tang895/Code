from flask import Flask,request

page=open('./page.html','r',encoding='utf-8')
page=''.join(page.readlines())
app=Flask(__name__)
@app.route('/',methods=['GET','POST'])
def hello():
    if request.method=='POST':
        if (request.form['user']=='admin' and request.form['pwd']=='1124'):
            return('登录成功')
        else:
            return('登录失败,账号或者密码错误<br>'+page)
    else:
        return page
print(app.url_map)
app.run(host='0.0.0.0',port=895)

