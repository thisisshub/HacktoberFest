import os
import glob
from zipfile import ZipFile
import PyPDF2
import re

keywords = input("Enter all keywords to search (, seperated) :").split(',')

zipfiles = []
for file in glob.glob("*.zip"):
    zipfiles.append('{}\{}'.format(os.getcwd(),file))

for file in zipfiles:
    z = ZipFile(file,'r')
    internal_files = z.infolist()
    for file_name in internal_files:
        try :
            file = z.open(file_name, 'r')
            fn = file.name
            efile = z.extract(file_name,os.getcwd())
            pdffile = open('{}\{}'.format(os.getcwd(),fn),'rb')
            pdfReader = PyPDF2.PdfFileReader(pdffile) 
            pageObj = pdfReader.getPage(0)
            text = pageObj.extractText()
            keywords_in_file = []
            for key in keywords:
                matches = re.finditer(key, text)
                matches_positions = [match.start() for match in matches]
                if len(matches_positions) > 0 :
                    keywords_in_file.append(key)
                    print('{} matches in file {} for {}'.format(len(matches_positions), fn, key))
            if len(keywords_in_file) > 0 :
                print('{} keys matched with file {}'.format(len(keywords_in_file), fn))                    
            pdffile.close()
        except UnicodeEncodeError:
            print('error in file: {} due to encoding check manually'.format(fn))
        except PermissionError:
            print('permission Error in file: {} check manually'.format(fn))
        except:
            print('unknown error occured in file : {} check manually'.format(fn))