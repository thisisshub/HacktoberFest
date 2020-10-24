# In 'numpy' we can convert values of matrix into 'integer' by 'np.matrix('1.4 0.6;1.8 3.2;1.4 4.2',dtype=int)' or 'matrix_variable.astype('int32')' but i created a function for this.
import numpy as np

def matrix_integer_values_any_shape(inp):			#* For any shape of matrix.
	lst=[]
	mtx=np.matrix([int(j) for i in np.array(inp) for j in i])
	for i in range(0,inp.shape[0]*inp.shape[1],inp.shape[1]):
		temp=[]
		[temp.append(mtx[0,i+j]) for j in range(inp.shape[1])],lst.append(temp)
	return np.matrix(lst)

print('Real Matrix with Floating Values:')
z_4_3=np.matrix('1.4 3.6 5.7 4.3;1.8 3.2 34.64 235.77;1.4 34.213 4.2 653.567')
print(z_4_3,z_4_3.shape,'\n')

print('With Self Created Function:')
z=matrix_integer_values_any_shape(z_4_3)
print(z,z.shape,'\n')

print('With Inbuilt Function:')
z=z.astype('int32')
print(z,z.shape,'\n')
