# READ !!
import sys
import re
import os
import subprocess

range_n = 8
pattern = 2 ** range_n
data_set = "M3"

rfile = open("m.cc","r")
rlines = rfile.readlines()

for i in range(pattern):
	rfile.seek(0)
	wfile = open("m_" + str(i) + ".cc","w")
	for rline in rlines:
		wline = re.sub("#define ZENTAN_ONII [0-9]+","#define ZENTAN_ONII "+str(i),rline)
		wline = re.sub("#define RANGE [0-9]+","#define RANGE "+str(range_n),wline)
		wfile.write(wline)
	wfile.close()
	
	compile_cc = subprocess.Popen(["c++","m_" + str(i) + ".cc"])
	compile_cc.wait()
	catter = subprocess.Popen(["cat",data_set],stdout=subprocess.PIPE)
	outter = subprocess.Popen(os.getcwd()+"/a.out",shell=True,stdin=catter.stdout,stdout=subprocess.PIPE)
	with open("out_"+str(i),"w") as outfile:
		for line in outter.stdout:
			outfile.write(line.rstrip()+"\n")
rfile.close()
