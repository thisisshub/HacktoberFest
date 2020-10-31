# MySQL Connectivity for database 'dbms2018'
# for table called PLAYLIST

import pymysql as mysql

try:
    db= mysql.connect("localhost","root","","dbms2018")
    cu=db.cursor()
    cu.execute("SELECT * FROM PLAYLIST GROUP BY MID ASC")
    data=cu.fetchall()
    for i in data:
        print("%-6s %-20s %-20s %-10s"%i)
        
    mid=int(input("Enter song id: "))
    stitle=input("Enter song title: ")
    sartist=input("Enter song artist: ")
    duration=input("Enter song duration: ")
    sql="""INSERT INTO playlist VALUES({},"{}","{}","{}")""".format(mid,stitle,sartist,duration)
    cu.execute(sql)
    db.commit()
    cu.execute("SELECT * FROM PLAYLIST GROUP BY MID ASC")
    data=cu.fetchall()
    for i in data:
        print("%-6s %-20s %-20s %-10s"%i)

    print("New Operation\n\n")
  
    qry="""UPDATE PLAYLIST SET SARTIST='Chainsmokers',STITLE='Closer' WHERE MID=9"""
    cu.execute(qry)
    cu.execute("SELECT * FROM PLAYLIST GROUP BY MID ASC")
    data=cu.fetchall()
    for i in data:
        print("%-6s %-20s %-20s %-10s"%i)

    qry2="""DELETE FROM PLAYLIST WHERE MID=45"""
    cu.execute(qry2)
    cu.execute("SELECT * FROM PLAYLIST GROUP BY MID ASC")
    data=cu.fetchall()
    for i in data:
        print("%-6s %-20s %-20s %-10s"%i)

finally:
    if(db.open):
       cu.close()
       db.close()
       print("MySQL connection is closed")
