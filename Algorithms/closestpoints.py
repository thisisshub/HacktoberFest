import math
import random


def dist(p1, p2):
    """
    Find the euclidean distance between two 2-D points
    Args:
        p1: (p1_x, p1_y)
        p2: (p2_x, p2_y)
    
    Returns:
        Euclidean distance between p1 and p2
    """
    distance= (((p2[1]-p1[1])**2)+((p2[0]-p1[0])**2))**0.5
    return distance

def sort_points_by_X(points):
    """
    Sort a list of points by their X coordinate
    Args:
        points: List of points [(p1_x, p1_y), (p2_x, p2_y), ...]
    
    Returns:
        List of points sorted by X coordinate
    """
    points.sort()
    return points




def sort_points_by_Y(points):
    """
    Sort a list of points by their Y coordinate
    Args:
        points: List of points [(p1_x, p1_y), (p2_x, p2_y), ...]
    
    Returns:
        List of points sorted by Y coordinate 
    """
    q=len(points)
    for i in range(q):
        for j in range(q-i-1):
            if points[j][1]>points[j+1][1]:
                temp=points[j]
                points[j]=points[j+1]
                points[j+1]=temp
    return points

def naive_closest_pair(plane):
    """
    Find the closest pair of points in the plane using the brute
    force approach
    Args:
        plane: List of points [(p1_x, p1_y), (p2_x, p2_y), ...]
    Returns:
        Distance between closest pair of points and closest pair 
        of points: [dist_bw_p1_p2, (p1_x, p1_y), (p2_x, p2_y)]
    """
    p1=plane[0]
    p2=plane[1]
    min=dist(plane[0],plane[1])
    for i in range(len(plane)):
        for j in range(i+1,len(plane)):
            if dist(plane[i],plane[j]) < min:
                min = dist(plane[i] , plane[j])
                p1=plane[i]
                p2=plane[j]
    return min,p1,p2



def closest_pair_in_strip(points, d):
    """
    Find the closest pair of points in the given strip with a 
    given upper bound. This function is called by 
    efficient_closest_pair_routine
    Args:
        points: List of points in the strip of interest.
        d: Minimum distance already found found by 
            efficient_closest_pair_routine
    Returns:
        Distance between closest pair of points and closest pair 
        of points: [dist_bw_p1_p2, (p1_x, p1_y), (p2_x, p2_y)] if
        distance between p1 and p2 is less than d. Otherwise
        return -1.
    """
    sort_points_by_Y(points)
    min=d
    for i in range(len(points)):
        if i+6<len(points):
            t=i+6
        else:
            t=len(points)
        for j in range (i+1,len(points)):
            if dist(points[i],points[j]) < min:
                min=dist(points[i],points[j])
                p1=points[i]
                p2=points[j]
    if min<d:
        return (min,p1,p2)
    else:
        return (-1,)






def efficient_closest_pair_routine(points):
    """
    This routine calls itself recursively to find the closest pair of
    points in the plane. 
    Args:
        points: List of points sorted by X coordinate
    Returns:
        Distance between closest pair of points and closest pair 
        of points: [dist_bw_p1_p2, (p1_x, p1_y), (p2_x, p2_y)]
    """
    if len(points)<=2:
        if len(points)==2:
            return (dist(points[0],points[1]),points[0],points[1])
        else:
            return (1000,points[0])

    n=len(points)//2
    mid=points[n]
    arr1=points[:n]
    #print (1,arr1)
    d1=efficient_closest_pair_routine(arr1)
    #print("d1",d1)
    arr2=points[n:]
    #print (2,arr2)
    d2=efficient_closest_pair_routine(arr2)
    #print("d2",d2)
    if (d1[0]<d2[0]):
        d=d1
    else:
        d=d2
    l=d[0]
    #print("l",l)
    newarr=[]
    for i in range(len(points)):
        if abs(points[i][0]-mid[0]) <l :
           newarr.append(points[i])
    #print(newarr)
    temp=closest_pair_in_strip(newarr,l)
    if temp[0]==-1:
        return d
    else:
        return closest_pair_in_strip(newarr, l)




def efficient_closest_pair(points):
    """
    Find the closest pair of points in the plane using the divide
    and conquer approach by calling efficient_closest_pair_routine.
    Args:
        plane: List of points [(p1_x, p1_y), (p2_x, p2_y), ...]
    Returns:
        Distance between closest pair of points and closest pair 
        of points: [dist_bw_p1_p2, (p1_x, p1_y), (p2_x, p2_y)]
    """
    sort_points_by_X(points)
    return efficient_closest_pair_routine(points)




def generate_plane(plane_size, num_pts):
    """
    Function to generate random points.
    Args:
        plane_size: Size of plane (X_max, Y_max)
        num_pts: Number of points to generate
    Returns:
        List of random points: [(p1_x, p1_y), (p2_x, p2_y), ...]
    """
    
    gen = random.sample(range(plane_size[0]*plane_size[1]), num_pts)
    random_points = [(i%plane_size[0] + 1, i//plane_size[1] + 1) for i in gen]

    return random_points



if __name__ == "__main__":
    #number of points to generate
    num_pts = 10
    #size of plane for generation of points
    plane_size = (10, 10) 
    plane = generate_plane(plane_size, num_pts)
    print(plane)
    print(naive_closest_pair(plane))
    print(efficient_closest_pair(plane))
