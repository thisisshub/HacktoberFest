//Palindrome
fun isPalindrome(s: String): Boolean {
  var reversed = ""
  for(i in s.indices.reversed())
    reversed = "$reversed${s.charAt(i)}"

    return s == reversed  
}