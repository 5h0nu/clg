import matplotlib.pyplot as plt
overs=[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
runs_scored=[0,7,12,20,39,49,61,83,86,97,113,116,123,137,145,163,172,192,198,198,203]
plt.plot(overs,runs_scored)
plt.xlabel('overs')
plt.ylabel('Runs scored')
plt.title('Runs scoring in an t20 cricket match')
plt.grid(True)
plt.show()
