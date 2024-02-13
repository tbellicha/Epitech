{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
module DoActions where
import SwitchList

doAllAct :: PSList -> [String] -> PSList
doAllAct (PSList a b) = foldl doActions (PSList a b)

doActions :: PSList -> String -> PSList
doActions (PSList a b) x
    | head x == 's' = doSwaps (PSList a b) x
    | head x == 'r' = doRotates (PSList a b) x
    | otherwise = doPushs (PSList a b) x

doSwaps :: PSList -> String -> PSList
doSwaps (PSList a b) "sa" = PSList (swapFirst a) b
doSwaps (PSList a b) "sb" = PSList a (swapFirst b)
doSwaps (PSList a b) "sc" = swapBoth (PSList a b)
doSwaps _ _ = PSList [] []

doRotates :: PSList -> String -> PSList
doRotates (PSList a b) "ra" = PSList (rotateList a) b
doRotates (PSList a b) "rb" = PSList a (rotateList b)
doRotates (PSList a b) "rc" = rotateBoth (PSList a b)
doRotates (PSList a b) "rra" = PSList (rotateRightList a) b
doRotates (PSList a b) "rrb" = PSList a (rotateRightList b)
doRotates (PSList a b) "rrc" = rotateRightBoth (PSList a b)
doRotates _ _ = PSList [] []

doPushs :: PSList -> String -> PSList
doPushs (PSList a b) "pa" = putA (PSList a b)
doPushs (PSList a b) "pb" = putB (PSList a b)
doPushs _ _ = PSList [] []