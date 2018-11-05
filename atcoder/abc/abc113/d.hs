import Control.Applicative
import Text.Printf
import Debug.Trace

fib n
  | n >= 1  = fib (n-1) + fib (n-2)
  | n >= -1 = 1
  | otherwise = 0xdeadbeef

mo = 1000000007 :: Integer

comb = fmap fib [0..8]


solve_ 1 w = take w $ [comb !! (w-2),comb !! max 0 (w-3)] ++ zs
  where zs = 0:zs
solve_ h w =
  let dp = solve_ (h-1) w
      c m n q = comb !! max 0 m * comb !! max 0 n * dp !! max 0 q `mod` mo
      left = ((c (w-2) 0 0) + (c (w-3) 0 1)) `mod` mo
      right = ((c (w-2) 0 (w-1)) + (c (w-3) 0 (w-2))) `mod` mo
      mid = [((c (x-2) (w-x-2) (x-1)) + (c (x-1) (w-x-2) x) + (c (x-1) (w-x-3) (x+1))) `mod` mo|x<-[1..w-2]]
--  in trace ("list:" ++ show (left:mid++[right])) (left:mid++[right])
  in left:mid++[right]

solve h w k = solve_ h w !! (k-1)

main = do
  [h,w,k] <- fmap (read :: String -> Int) . words <$> getLine
  if w == 1 then
    printf "1\n"
  else printf "%d\n" $ solve h w k `mod` mo

