{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
import GHC.IO.Exception (ExitCode(ExitFailure))
import System.Exit ( exitWith )
import CheckArgs
import DoActions
import System.Directory.Internal.Prelude
import SwitchList
import SwitchList (PSList(PSList))

main :: IO ()
main = do
    args <- getArgs
    cmds <- getLine
    let allCmd = words cmds
    if checkArgsType args && checkOperations allCmd 
        then diRes $ isSortedPSL (doAllAct (PSList (argsToInt args) []) allCmd)
        else exitWith $ ExitFailure 84
