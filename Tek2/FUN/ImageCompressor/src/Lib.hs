module Lib where

import Data.List ()
import System.Exit ( exitWith, ExitCode(ExitFailure) )
import Text.Read ( readMaybe )

data Pos = Pos Int Int
instance Show Pos where
    show (Pos x y) = "(" ++ show x ++ "," ++ show y ++ ")"

data Color = Color Int Int Int
instance Show Color where
    show (Color r g b) = "(" ++ show r ++ "," ++ show g ++ "," ++ show b ++ ")"

data Pixel = Pixel Pos Color
instance Show Pixel where
    show (Pixel pos color) = show pos ++ " " ++ show color

displayHelper :: IO ()
displayHelper = putStrLn "USAGE: ./imageCompressor -n N -l L -f F\n" >>
        putStrLn "\tN\tnumber of colors in the final image" >>
        putStrLn "\tL\tconvergence limit" >>
        putStrLn "\tF\tpath to the file containing the colors of the pixels"

exitError :: IO a
exitError = exitWith (ExitFailure 84)

getNumberColor:: [String] -> Maybe Int
getNumberColor (a:b:cx)
    | a == "-n" = readMaybe b :: Maybe Int
    | null cx = Nothing
getNumberColor (a:b:cx) = getNumberColor cx

getConvLimit:: [String] -> Maybe Double
getConvLimit (a:b:cx)
    | a == "-l" = readMaybe b :: Maybe Double
    | null cx = Nothing
getConvLimit (a:b:cx) = getConvLimit cx

getFileArg :: [String] -> String
getFileArg (a:b:cx)
    | a == "-f" = b
    | null cx = ""
getFileArg (a:b:cx) = getFileArg cx

getDistance ::
    Double -> Double -> Double -> Double -> Double -> Double -> Double
getDistance xa ya za xb yb zb = sqrt((xb-xa)^2 + (yb-ya)^2 + (zb-za)^2)

pixelToColor :: Pixel -> (Double, Double, Double)
pixelToColor (Pixel pos (Color r g b)) =
    (fromIntegral r, fromIntegral g, fromIntegral b)

getRGB :: Int -> (Double, Double, Double) -> Double
getRGB nbr (r, g, b)
    | nbr == 1 = r
    | nbr == 2 = g
    | nbr == 3 = b
    | otherwise = 0