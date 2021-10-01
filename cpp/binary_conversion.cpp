string binconv(int no)
{
    bitset<30> b(no);
    string bin = b.to_string();
    int f = bin.find_first_of("1");
    if(f!=-1) return bin.substr(f);
    else return "0";
}