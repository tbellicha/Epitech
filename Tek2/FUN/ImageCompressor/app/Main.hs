module Main where

import Lib

import Control.Exception ( SomeException, catch )
import Data.Char ()
import Data.List ( sort, elemIndex )
import Data.Maybe ( fromJust, isNothing, mapMaybe )
import Data.String ()
import Data.Typeable ()
import Numeric ( showFFloat )
import System.Environment ( getArgs )
import System.Random ( newStdGen, Random(randomR), StdGen )
import Text.Read ( readMaybe )

main :: IO ()
main = do
    args <- getArgs
    compute args

compute :: [String] -> IO ()
compute [] = displayHelper >> exitError
compute args
    | isNothing n = displayHelper >> exitError
    | isNothing l = displayHelper >> exitError
    | fromJust n < 1 = displayHelper >> exitError
    | otherwise = readFilepath (fromJust n) filepath
    where
        n = getNumberColor args
        l = getConvLimit args
        filepath = getFileArg args

readFilepath :: Int -> String -> IO ()
readFilepath n filepath = do
    file <- catch (readFile filepath) error
    rdm <- newStdGen
    let pixels = mapMaybe readLine(lines file)
        cluster = map pixelToColor(createCluster pixels [] n rdm)
        cluster_index = map(getClusterPos 0 (-1) (-1) cluster) pixels
    myLoop n pixels cluster_index cluster
    where
        error :: SomeException -> IO String
        error ex = putStrLn (filepath ++ ": No such file.") >> exitError

readLine :: String -> Maybe Pixel
readLine curLine = let i = elemIndex ')' curLine
                    in case i of
                    Just i -> convPosColorToPixel pos color
                        where
                            f = splitAt (i + 1) curLine
                            pos = readMaybe(fst f) :: Maybe (Int, Int)
                            color = readMaybe(snd f) :: Maybe (Int, Int, Int)
                    Nothing -> Nothing

convPosColorToPixel :: Maybe (Int, Int) -> Maybe (Int, Int, Int) -> Maybe Pixel
convPosColorToPixel Nothing _ = Nothing
convPosColorToPixel _ Nothing = Nothing
convPosColorToPixel (Just(pX, pY)) (Just(cR, cG, cB))
    | pX < 0 || pY < 0 = Nothing
    | cR < 0 || cR > 255 || cG < 0 || cG > 255 || cB < 0 || cB > 255 = Nothing
    | otherwise = Just(Pixel (Pos pX pY) (Color cR cG cB))

getClusters :: [Pixel] -> [Int] -> Int -> [[Pixel]]
getClusters pixel i n = [[pixel!!y | y <- [0..(length i -1)],
    x == (i!!y)] | x <- [0..(n - 1)]]

createCluster :: [Pixel] -> [Pixel] -> Int -> StdGen -> [Pixel]
createCluster array list k gen
    | k <= 0 = list
    | otherwise = createCluster array (list ++ [array!!rdm]) (k-1) rdm2
    where
        (rdm, rdm2) = randomR (0, length array -1) gen

getClusterPos ::
    Int -> Double -> Int -> [(Double, Double, Double)] -> Pixel -> Int
getClusterPos i distanceMin min cluster pixel
    | length cluster > i = doClusters i distanceMin min pixel pixel cluster
    | otherwise = min

doClusters ::
    Int -> Double -> Int -> Pixel -> Pixel -> [(Double, Double, Double)] -> Int
doClusters i distanceMin min pixel (Pixel pos (Color rA gA bA)) cluster
    | min < 0 || getDistance rB gB bB
        (fromIntegral rA) (fromIntegral gA) (fromIntegral bA) < distanceMin =
        getClusterPos (i + 1) (getDistance rB gB bB
        (fromIntegral rA) (fromIntegral gA) (fromIntegral bA)) i cluster pixel
    | otherwise = getClusterPos (i + 1) distanceMin min cluster pixel
    where
        (rB, gB, bB) = cluster!!i

myLoop :: Int -> [Pixel] -> [Int] -> [(Double, Double, Double)] -> IO()
myLoop n pixel i cluster = do
    let newCluster = createNewCluster(getClusters pixel i n) n 0 cluster []
        newI = map(getClusterPos 0 (-1) (-1) newCluster) pixel
    if sort i /= sort newI
        then myLoop n pixel newI newCluster
    else do
        mapM_ displayRes(zip cluster (getClusters pixel i n))

createNewCluster ::
    [[Pixel]] -> Int -> Int -> [(Double, Double, Double)] ->
        [(Double, Double, Double)] -> [(Double, Double, Double)]
createNewCluster clusterTab k i clusters newClusters = do
    let tab = map pixelToColor(clusterTab!!i)
    if i < k
        then
            fixCluster clusterTab (map(getRGB 1) tab) (map(getRGB 2) tab)
                (map(getRGB 3) tab) k i clusters newClusters
        else
            newClusters

fixCluster :: [[Pixel]] -> [Double] -> [Double] -> [Double] -> Int -> Int ->
    [(Double, Double, Double)] -> [(Double, Double, Double)] ->
        [(Double, Double, Double)]
fixCluster clusterTab rA gA bA k i clusters newClusters = do
    let r = sum rA / fromIntegral(length rA)
        g = sum gA / fromIntegral(length gA)
        b = sum bA / fromIntegral(length bA)
    createNewCluster clusterTab k (i + 1) clusters (newClusters ++ [(r, g, b)])

displayRes :: ((Double, Double, Double), [Pixel]) -> IO ()
displayRes ((r, g, b), pixel) = do
    putStrLn ("--\n(" ++ showFFloat(Just 0) r "" ++ "," ++
        showFFloat(Just 0) g "" ++ "," ++ showFFloat(Just 0) b "" ++ ")\n-")
    mapM_ print pixel