    import os 
    import shutil 
     
    FileCount = 0  #to keep a record how much files are totally moved. 
    filelist = []     #to make list of filenames of particular extension 
    ext = str(input())    
    target = 'F:\\exe'  # destination folder where all files with similar extension will be saved. 
     
    for foldername, subfolders, filenames in os.walk('F:\\'):     
        for filename in filenames: 
            if foldername == 'F:\\exe':  # to skip the destination folder. 
                continue 
            elif filename.endswith(ext): 
                FileCount+=1; 
                filelist.append(filename) 
                shutil.move(f'{foldername}\{filename}',target) # moving files to destination folder. 
                 
     
    print(FileCount) 
    print(filelist) 
