import datetime
import re
import time
from selenium import webdriver
import os
print("오늘의 문제를 가져옵니다...")
today = datetime.datetime.today().strftime("%Y-%m-%d")
print(today)
url = "https://brilliant.org/daily-problems/"
options = webdriver.ChromeOptions()
options.add_argument('headless')
options.add_argument('window-size=1920x1080')
options.add_argument('disable-gpu')
driver = webdriver.Chrome('chromedriver', options=options)

driver.get(url)

path = "../Problems"+"\\"+today

# 문제를 url 가져오기
get_url = driver.find_elements_by_css_selector("div.nf-feed-item > div > a")

# 앞에 두개 링크가 오늘의 문제다.
problem_url = [get_url[0].get_attribute("href"), get_url[1].get_attribute("href")]
print(problem_url)
# 문제를 크롤링 하는 함수 작성
def cleanText(readData):
    #텍스트에 포함되어 있는 특수 문자 제거
    text = re.sub('[-=+,#/\?:^$.@*\"※~&%ㆍ!』\\‘|\(\)\[\]\<\>`\'…》]', '', readData)
    return text

def blank_delete(text): #html가져올때 무분별한 탭때문에 인식이 이상하게되는것을 해결하기 위해 사용
    lis = text.split("\n")
    result = ""
    for i in lis:
        i = i.lstrip()
        result = result + i + "\n"
    return result

def crawl_problem(url):
    driver.get(url)
    title = driver.find_element_by_css_selector("#cmp_daily_problems_main_body_id > div > div > header > h2").text
    title = title.replace(" ", "")
    # 폴더 있는지 확인하고 생성
    if not os.path.exists(path):
        os.makedirs(path)
    # 파일이 이미 존재하면 종료
    if os.path.exists(path + "\\" + cleanText(title) + ".md"):
        print("이미 생성된 파일이 존재합니다.\n%s\n프로그램을 종료합니다." % (path + "\\" + cleanText(title) + ".md"))
        time.sleep(1)
        exit(-1)
    f = open(path + "\\" + cleanText(title) + ".md", 'w', encoding='UTF-8')

    # 제목
    f.write("# " + title+"\n")
    f.write(url+"\n\n")
    # 내용
    story = driver.find_elements_by_css_selector("#cmp_daily_problems_main_body_id > div > div > div > div > div.head.b-vspace-m")
    btn = driver.find_element_by_css_selector("#dp-expand")
    btn.click()
    tail = driver.find_elements_by_css_selector("#cmp_daily_problems_main_body_id > div > div > div > div > div.tail")
    today_problem = driver.find_elements_by_css_selector("#cmp_logged_out_daily_problems_problem_id > div > div.problem-content")
    select = driver.find_elements_by_css_selector("#cmp_logged_out_daily_problems_problem_id > div > div.dp-solv-details.solv-details.clearfix.mcq.logged-out > div > form > label")

    for i in story:
        f.write(blank_delete(i.get_attribute("innerHTML")) + "\n")
    f.write("\n")
    for i in tail:
        f.write(blank_delete(i.get_attribute("innerHTML")) + "\n")

    for i in today_problem:
        f.write(blank_delete(i.get_attribute("innerHTML")) + "\n")
    print(select)
    for i in select:
        f.write("* "+i.text + "\n")

    f.write("\n===============================================\n")
    # 한국 번역 부분
    f.write("\n\n\n# 내 멋대로 발직역\n")
    f.write("# 제목\n")

    for i in today_problem:
        f.write(blank_delete(i.get_attribute("innerHTML")) + "\n")
    print(select)
    for i in select:
        f.write("* "+i.text + "\n")

    f.write("\n===============================================\n\n")
    f.write("내가 고른 정답 : \n\n")
    f.write("이유 : \n\n")
    f.write("정답 : \n\n")
    f.write("모범 답안 : \n\n")
    f.close()

for i in problem_url:
    crawl_problem(i)