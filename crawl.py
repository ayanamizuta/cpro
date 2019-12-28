import os,sys
import ssl
ssl._create_default_https_context = ssl._create_unverified_context
import urllib.request
from bs4 import BeautifulSoup

contest = sys.argv[1]
problems = ["a","b","c","d","e","f"]

for x in problems:
    os.makedirs(os.path.join(os.getcwd(),"test",x), exist_ok=True)

def trim(s):
    s = s.replace("&gt;",">")
    s = s.replace("&lt;","<")
    return s

for x in problems:
    _res = urllib.request.urlopen(f"http://atcoder.jp/contests/{contest}/tasks/{contest}_{x}")
    res = _res.read()
    s = str(BeautifulSoup(res))
    init_tag = "<pre>"
    term_tag = "</pre>"
    for i in range(1,10):
        if s.find(f"入力例 {i}") == -1:
            break
        os.makedirs(os.path.join(os.getcwd(),"test",x,str(i)), exist_ok=True)
        s = s[s.find(f"入力例 {i}"):]
        s = s[s.find(init_tag)+len(init_tag):]
        f = open(os.path.join(os.getcwd(),"test",x,str(i),"input.txt"),"w+")
        f.write(trim(s[:s.find(term_tag)]))

        s = s[s.find(f"出力例 {i}"):]
        s = s[s.find(init_tag)+len(init_tag):]
        f = open(os.path.join(os.getcwd(),"test",x,str(i),"output.txt"),"w+")
        f.write(trim(s[:s.find(term_tag)]))

