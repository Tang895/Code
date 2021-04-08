import requests

import re#正则
import os #创建文件夹用
#糗事百科图片爬取
import json
headers={
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) '
         'AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.83 Safari/537.36 Edg/85.0.564.41'
}
#url="https://www.qiushibaike.com/imgrank/"
for page in range(2,13):
    pages=str(page)

    url = "https://www.qiushibaike.com/imgrank/page/" + pages + "/"

    response = requests.get(url=url, headers=headers)

    page_origin = response.text

    # 爬取图片链接
    # 所有图片所在标签ID为class

    # <div class="thumb">
    #
    # <a href="/article/123532830" target="_blank">
    # <img src="//pic.qiushibaike.com/system/pictures/12353/123532830/medium/76ZDSC6TAZI32FFB.jpg" alt="糗事#123532830" class="illustration" width="100%" height="auto">
    # </a>
    # </div>

    # 正则表达式编写

    ex = '<div class="thumb">.*?<img src="(.*?)" alt.*?</div>'
    img_list = re.findall(ex, page_origin, re.S)  # re.S 单行匹配 re.M多行匹配
    print(img_list)
    # 创建文件夹
    if not os.path.exists('./img'):
        os.mkdir('./img')

    for src in img_list:
        src = 'https:' + src  # 需要加协议头
        img_response = requests.get(url=src, headers=headers).content  # content表示二进制存储
        # 保存
        # 生成图片的名称
        img_name = src.split('/')[-1]

        imgPath = './img/' + img_name
        with open(imgPath, 'wb') as fp:
            fp.write(img_response)
            print("成功")



