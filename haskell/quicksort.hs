qsort [] = []
qsort (x:xs) = (qsort small) ++ (x:(qsort big))
  where small = [n | n <- xs, n < x]
        big = [n | n <- xs, n > x]