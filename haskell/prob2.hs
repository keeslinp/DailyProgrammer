fibs :: [Int]
fibs = 0 : 1 : [ a + b | (a, b) <- zip fibs (tail fibs)]
main = print(sum [x | x <- takeWhile(<=4000000) fibs, even x])
