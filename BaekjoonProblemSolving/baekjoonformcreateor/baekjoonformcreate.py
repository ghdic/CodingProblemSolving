from bs4 import BeautifulSoup
import requests
import os
import time
import re


def cleanText(readData):
    #텍스트에 포함되어 있는 특수 문자 제거
    text = re.sub('[\/:*\?\"\\‘|\<\>`\']', ' ', readData)
    return text


print("문제 url를 입력해주세요")
url = input()

req = requests.get(url)
soup = BeautifulSoup(req.text, 'html.parser')

problem = url.split("/")[-1]
if url.find("contest") != -1:
    title = soup.find("div", {"class": "page-header"})
    title = title.get_text().replace("\n","")
    title = cleanText(title)
    problem = title

# ============================================================
path = "../BaekjoonProblemSolving"
if(os.path.exists(path+"\\"+problem+".cpp")):
    print("file exist!")
    time.sleep(1)
    exit(-1)
f = open(path+"\\"+problem +".cpp", 'w', encoding='UTF-8')
# ============================================================
f.write("/*\n")
f.write(url + "\n\n")

f.write("&Title\n")
title = soup.find("div", {"class": "page-header"})
title = title.get_text().replace("\n","")
title = cleanText(title)
f.write(title + "\n\n")

f.write("&Question\n")
problem_description = soup.find("div", {"id": "problem_description"})
problem_description = problem_description.get_text().replace("\n","")
problem_description = problem_description.split()
cnt=0
str=""
for kk in problem_description:
    str+=kk+" "
    cnt+=1
    if(cnt%9==8):
        str+="\n"
str+="\n\n"
f.write(str)

f.write("&Input\n")
problem_input = soup.find("div", {"id": "problem_input"})
problem_input = problem_input.get_text().replace("\n","")
problem_input = problem_input.split()
cnt=0
str=""
for kk in problem_input:
    str+=kk+" "
    cnt+=1
    if(cnt%9==8):
        str+="\n"
str+="\n\n"
f.write(str)

f.write("&Output\n")
problem_output = soup.find("div", {"id": "problem_output"})
problem_output = problem_output.get_text().replace("\n","")
problem_output = problem_output.split()
cnt=0
str=""
for kk in problem_output:
    str+=kk+" "
    cnt+=1
    if(cnt%9==8):
        str+="\n"
str+="\n\n"
f.write(str)

f.write("&Example\n")
sampledata = soup.find_all("pre", {"class": "sampledata"})
cnt=0
for kk in sampledata:
    if cnt%2==0:
        f.write("-input\n")
    else:
        f.write("-output\n")
    str=kk.get_text().replace("\r", "")
    f.write(str+"\n")
    cnt+=1

f.write("\n*/"+"\n\n\n")

f.write("#include <iostream>\nusing namespace std;\n\nint main() {\n	int N;\n	setbuf(stdout, NULL);\n	ios::sync_with_stdio(false);\n	return 0;\n}\n")
f.close()
time.sleep(1)