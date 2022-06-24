#find and replace gate names
def replace_bench(filedata):
	lines = filedata.split('\n')
	for i in range(len(lines)):
		l = lines[i]
		lines[i] = l.replace('DFFRSE', 'DFF')
		if (l.find(',') > -1):
			if (l.find('LUT 0x8') > -1):
				lines[i] = l.replace('LUT 0x8', 'AND')
			elif (l.find('LUT 0x7') > -1):				
				lines[i] = l.replace('LUT 0x7', 'NAND') 
			elif (l.find('LUT 0x1') > -1):
				lines[i] = l.replace('LUT 0x1', 'NOR')
		else:
			if (l.find('LUT 0x1') > -1):
				lines[i] = l.replace('LUT 0x1', 'NOT')
			elif (l.find('LUT 0x2') > -1):
				lines[i] = l.replace('LUT 0x2', 'BUF')
	return "\n".join(lines)
	