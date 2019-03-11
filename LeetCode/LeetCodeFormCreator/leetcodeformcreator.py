from bs4 import BeautifulSoup
import requests
import os
import time
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.common.by import By
print("문제 url을 입력해주세요")
url = input()
options = webdriver.ChromeOptions()
#options.add_argument('headless')
options.add_argument('window-size=1920x1080')
options.add_argument('disable-gpu')
driver = webdriver.Chrome('chromedriver', options=options)

driver.get(url)

# 로딩 창이 끝날때까지 기다린다.
# title원소를 찾으면 성공 10초가 지나면
try:
    element = WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.CSS_SELECTOR, "div.css-v3d350"))
    )
except TimeoutException:
    print("타임아웃")
    time.sleep(1)
    exit(-1)

# ============================================================
path = "../LeetCodeSolvingProblem"
title = driver.find_element_by_css_selector("div.css-v3d350").text
if(os.path.exists(path+"\\"+title+".cpp")):
    print("file exist!")
    time.sleep(1)
    exit(-1)
f = open(path+"\\"+title +".cpp", 'w', encoding='UTF-8')
# ============================================================
f.write("/*\n")
f.write(url + "\n\n")

f.write("&Title\n")
f.write(title + "\n\n")

problem = driver.find_element_by_css_selector("div.content__eAC7").text
f.write("&Question\n")
problem_description = problem.split('\n')
cnt=0
str=""
length_num = 50
for kk in problem_description:
    while len(kk) > length_num:
        str+=kk[0:length_num]+'\n'
        kk=kk[length_num:]
    str+=kk+'\n'
f.write(str)
f.write("\n*/"+"\n\n\n")
form = driver.find_elements_by_css_selector("pre.CodeMirror-line")
for kk in form:
    f.write(kk.text+'\n')

f.close()
time.sleep(1)

driver.quit()