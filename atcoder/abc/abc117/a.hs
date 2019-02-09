import Control.Applicative
import Text.Printf
import Debug.Trace

main :: IO ()
main = do
  [t,x] <- fmap (read :: String -> Double) . words <$> getLine
  printf "%.10f\n" (t/x)
