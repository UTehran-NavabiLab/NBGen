import re 

string = "$paramod\\aftab_adder\\size=s32'00000000000000000000000000100000"
string = "\\aftab_ad[d]er"
x = re.sub("['.~\[\]!@#$%^&*\\\+=-]", "_", string)
print(x)