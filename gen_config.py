import json
fp=open("/home/nvidia/FujiClassifier/label.json")
label=json.load(fp)
fp=open("/home/nvidia/FujiClassifier/enabled_label.json")
enabled_label=json.load(fp)
target_label=[label[str(lid)] for lid in enabled_label]


print('version: "1.0"')
dx=-0.12
x_min=-0.9+dx
x_max=0.8+dx
y=-0.2
rad=-1.2

num=len(target_label)

dx=(x_max-x_min)/(num-1)
for i in range(num):
	x=x_min+dx*i
	
	print('labels {')
	print('name: "label%d"'%(i))
 	print('text: "%s"'%(target_label[i]))
	print('x: %f'%(x))
	print('y: %f'%(y))
	print('rad: %f'%(rad))
	print('}')

