import Control.Applicative
import Text.Printf
import Debug.Trace

main = do
  [hoge,fuga] <- fmap (read :: String -> Int) . words <$> getLine
  n <- readLn
  printf "%d\n" $ solve hoge fuga
