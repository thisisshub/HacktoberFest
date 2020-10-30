//Index of Maximum
fun _indexOfMax(a: IntArray): Int? { 
        var maxIndex = 0
            for(elem in a.indices){
            val newElem = a[elem]
            if (newElem >= a[maxIndex]){
                 maxIndex = elem; 
            }
    	}
        return maxIndex
    }
    return  if(a.size != 0) _indexOfMax(a) else null