import os,sys,glob
import subprocess

problem = sys.argv[1]
subprocess.run(["g++",f"{problem}.cpp","-I","../../../"])

for x in glob.glob(os.getcwd()+f"/test/{problem}/*"):
    _input = open(x+"/input.txt","r").read()
    result = subprocess.check_output(["./a.out"],input=_input.encode("utf-8")).decode("utf-8")
    answer = open(x+"/output.txt").read()
    if result == answer:
        print(x,"ok!!!")
    else:
        print(x,"failed!!!")
        print("input")
        print(_input)
        print("answer")
        print(answer)
        print("result")
        print(result)