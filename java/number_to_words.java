class Main
{
    private static final String EMPTY = "";
 
    private static final String[] X =
    {
        EMPTY, "One ", "Two ", "Three ", "Four ", "Five ", "Six ",
        "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ","Twelve ",
        "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ",
        "Seventeen ", "Eighteen ", "Nineteen "
    };
 
    private static final String[] Y =
    {
        EMPTY, EMPTY, "Twenty ", "Thirty ", "Forty ", "Fifty ",
        "Sixty ", "Seventy ", "Eighty ", "Ninety "
    };
 
    // Function to convert a single-digit or two-digit number into words
    private static String convertToDigit(int n, String suffix)
    {
        // if `n` is zero
        if (n == 0) {
            return EMPTY;
        }
 
        // split `n` if it is more than 19
        if (n > 19) {
            return Y[n / 10] + X[n % 10] + suffix;
        }
        else {
            return X[n] + suffix;
        }
    }
 
    // Function to convert a given number (max 9-digits) into words
    public static String convert(int n)
    {
        // for storing the word representation of the given number
        StringBuilder res = new StringBuilder();
 
        // add digits at ten million and hundred million place
        res.append(convertToDigit((n / 1000000000) % 100, "Billion, "));
 
        // add digits at ten million and hundred million place
        res.append(convertToDigit((n / 10000000) % 100, "Crore, "));
 
        // add digits at hundred thousand and one million place
        res.append(convertToDigit(((n / 100000) % 100), "Lakh, "));
 
        // add digits at thousand and tens thousand place
        res.append(convertToDigit(((n / 1000) % 100), "Thousand "));
 
        // add digit at hundred place
        res.append(convertToDigit(((n / 100) % 10), "Hundred "));
 
        if ((n > 100) && (n % 100 != 0)) {
            res.append("and ");
        }
 
        // add digits at ones and tens place
        res.append(convertToDigit((n % 100), ""));
 
        return res.toString();
    }
 
    // Java program to convert numbers to words
    public static void main(String[] args)
    {
        System.out.println(convert(99));
        System.out.println(convert(1000));
        System.out.println(convert(14632));
        System.out.println(convert(997751076));
        System.out.println(convert(Integer.MAX_VALUE));    // 2147483647
    }
}
