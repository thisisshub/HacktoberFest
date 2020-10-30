//function that calculate sum of numbers in Kotlin
fun sum(a: IntArray): Int {
  var _sum = 0
  for(element in a)
    _sum += element       
    
  return _sum