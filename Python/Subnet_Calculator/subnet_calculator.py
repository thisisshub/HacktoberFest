
import random
import sys

def subnet_calc():
    try:
        print("\n Subnet Calculator")
        
        while True:
            ip_address = input("Enter an IP Address: ")
            
            ##Splitting IP Address into Octets 
            ip_octets=ip_address.split('.')
            
            ##Need to check if only 4 octets are only present and if  IPs are in range
            if  len(ip_octets) == 4 and  1 <= int(ip_octets[0]) <=223  and 0<= int (ip_octets[1])<=255 and 0<= int (ip_octets[2])<=255 and 0<= int (ip_octets[3])<=255:
                break
            else:
                print("\n The IP Address is INVALID! Please retry \n")
                continue
        masks=[255,254,252,248,240,224,192,128,0]
        
        while True:
            subnet_mask=input("Enter a subnet mask: ")
            
            ##Splitting Subnet Mask into Subnet Octets
            mask_octets=subnet_mask.split('.')
            
            if len(mask_octets) == 4 and int(mask_octets[0]) == 255 and int(mask_octets[1]) in masks and int(mask_octets[2]) in masks and int(mask_octets[3]) in masks and int(mask_octets[0]) >= int(mask_octets[1]) >= int(mask_octets[2]) >= int(mask_octets[3]):
                break
            else:
                print("\nThe subnet mask is INVALID! Please retry!\n")
                continue
            
        mask_octets_binary=[]
        for octet in mask_octets:
            
            #Binary function  will convert into binary with 0b prepended
            binary_octet=bin(int(octet)).lstrip('0b')
            
            ##Padding the bits to make it into 8 bit format
            mask_octets_binary.append(binary_octet.zfill(8))
            
        ##mask_octets_binary is in a list so the entries must be made into a string
        binary_mask="".join(mask_octets_binary)
        
        no_of_zeroes=binary_mask.count("0")
        no_of_ones=32-no_of_zeroes
        no_of_hosts=abs((2**no_of_zeroes) -2 )
        
        ip_octets_padded=[]
        ip_octets_decimal=ip_address.split(".")
        
        for octet_index in range(0, len(ip_octets_decimal)):
            binary_octet = bin(int(ip_octets_decimal[octet_index])).split("b")[1]
            
            if len(binary_octet) < 8 :
                binary_octet_padded=binary_octet.zfill(8)
                ip_octets_padded.append(binary_octet_padded)
                
            else:
                ip_octets_padded.append(binary_octet)
        binary_ip = "".join(ip_octets_padded)
        
        network_address_binary = binary_ip[:(no_of_ones)] + "0" * no_of_zeroes
        
        broadcast_address_binary = binary_ip[:(no_of_ones)] + "1" * no_of_zeroes
        
        net_ip_octets = []
        for octet in range(0, len(network_address_binary), 8):
            net_ip_octet = network_address_binary[octet:octet+8]
            net_ip_octets.append(net_ip_octet)
        
        net_ip_address = []
        for each_octet in net_ip_octets:
            
            #int(x=0, base=10)
            net_ip_address.append(str(int(each_octet, 2)))
        
        network_address = ".".join(net_ip_address)
        
        bst_ip_octets = []
        for octet in range(0, len(broadcast_address_binary), 8):
            bst_ip_octet = broadcast_address_binary[octet:octet+8]
            bst_ip_octets.append(bst_ip_octet)
        
        bst_ip_address = []
        for each_octet in bst_ip_octets:
            bst_ip_address.append(str(int(each_octet, 2)))
        
        broadcast_address = ".".join(bst_ip_address)
        print(broadcast_address)
        
        
        print("Network address is: %s" % network_address)
        print("Broadcast address is: %s" % broadcast_address)
        print("Number of valid hosts per subnet: %s" % no_of_hosts)
        print("Mask bits: %s" % no_of_ones)
        
        
        

    except KeyboardInterrupt:
        print("\n\nProgram aborted by user. Exiting...\n")
        sys.exit()
        
        
        
subnet_calc()