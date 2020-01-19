#!/usr/bin/python3
import random
#--------------------------------------------------
# Set initial etaus state
#--------------------------------------------------
s1 = random.getrandbits(32)
s2 = random.getrandbits(32)
s3 = random.getrandbits(32)
prev = random.getrandbits(32)
pprev = random.getrandbits(32)
s = random.getrandbits(32)
#--------------------------------------------------
# Set constant variables
#--------------------------------------------------
maxint = 65536 * 65536
half   = maxint >> 1
mask   = maxint - 1
num = 0
#--------------------------------------------------
# Initialize 16384 Bays-Durham registers
#--------------------------------------------------
bays = []
i = 0
while (i < 16384):
	num = random.getrandbits(32)
	bays.append(num)
	i = i + 1
#--------------------------------------------------
# Calculate expected binomial values
#--------------------------------------------------
expected = []
expected.append(1.0)
expected.append(17.0)
expected.append(136.0)
expected.append(680.0)
expected.append(2380.0)
expected.append(6188.0)
expected.append(12376.0)
expected.append(19448.0)
expected.append(24310.0)
expected.append(24310.0)
expected.append(19448.0)
expected.append(12376.0)
expected.append(6188.0)
expected.append(2380.0)
expected.append(680.0)
expected.append(136.0)
expected.append(17.0)
expected.append(1.0)
#--------------------------------------------------
# Calculate total expected binomial values
#--------------------------------------------------
totexp = 0.0
i = 0
while i <= 17:
	totexp = totexp + expected[i]
	i = i + 1
print('total expected', totexp)
#--------------------------------------------------
# Initialize actual tally array
#--------------------------------------------------
actual = []
i = 0
while i <= 17:
	actual.append(0.0)
	i = i + 1
#--------------------------------------------------
# Run 2^17 random trials
# Each trial flips a coin 17 times to see how
# many heads there are
# Tabulate by number of heads flipped
#--------------------------------------------------
i = 0
lmt = int(totexp)
while i < lmt:
	heads = 0
	tmp = 0
	k = 0
	j = 0
	while j < 17:
                #--------------------------------------------------
		# etaus random number generator
                #--------------------------------------------------
		pprev = prev
		prev = s
		s1 = (((s1&4294967294)<<12)^(((s1<<13)^s1)>>19))
		s2 = (((s2&4294967288)<<4)^(((s2<<2)^s2)>>25))
		s3 = (((s3&4294967280)<<17)^(((s3<<3)^s3)>>11))
		s1 = s1 & mask
		s2 = s1 & mask
		s3 = s1 & mask
		s = (s1 ^ s2 ^ s3) & mask
		k = pprev & 16383
		tmp = bays[k]
		bays[k] = s
		s = tmp & mask
		out = (s ^ prev ^ pprev) & mask
                #--------------------------------------------------
		# add up number of heads flipped
                #--------------------------------------------------
		if out >= half: heads = heads + 1
		j = j + 1
        #--------------------------------------------------
	# number of trials with n heads flipped
	# where n is from zero to 17
        #--------------------------------------------------
	actual[heads] = actual[heads] + 1.0
	i = i + 1
#--------------------------------------------------
# list actual by number of heads flipped
#--------------------------------------------------
print('#Heads Actual')
i = 0
while i <= 17:
	print(i, actual[i])
	i = i + 1
#--------------------------------------------------
# Chi square test
# Print differences by number of heads flipped
#--------------------------------------------------
print('#Heads Difference  Chi Square')
diff = 0.0
diffsq = 0.0
chisq = 0.0
i = 0
while i <= 17:
	diff = actual[i] - expected[i]
	diffsq = diff * diff
	chisq = chisq + (diffsq / expected[i])
	print(i, diff, chisq)
	i = i + 1
print('Binomial Distribution Test');
print('Python etaus generator');
print('Chi Square', chisq)
print('Chi square ranges between 7.564186 and 30.191009')
print('at 95% confidence and 17 degrees of freedom,')
