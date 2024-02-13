import Test.HUnit
import My

mySucc1 = TestCase (assertEqual "for (mySucc 42)" (43) (mySucc 42))
mySucc2 = TestCase (assertEqual "for (mySucc (-1))" (0) (mySucc (-1)))

myIsNeg1 = TestCase (assertEqual "for (myIsNeg 42)" (False) (myIsNeg 42))
myIsNeg2 = TestCase (assertEqual "for (myIsNeg (-1))" (True) (myIsNeg (-1)))
myIsNeg3 = TestCase (assertEqual "for (myIsNeg 3)" (False) (myIsNeg 0))

myAbs1 = TestCase (assertEqual "for (myAbs 42)" (42) (myAbs 42))
myAbs2 = TestCase (assertEqual "for (myAbs (-1))" (1) (myAbs (-1)))
myAbs3 = TestCase (assertEqual "for (myAbs 0)" (0) (myAbs 0))

myMin1 = TestCase (assertEqual "for (myMin 42 84)" (42) (myMin 42 84))
myMin2 = TestCase (assertEqual "for (myMin 84 42)" (42) (myMin 84 42))
myMin3 = TestCase (assertEqual "for (myMin 84 (-42))" (-42) (myMin 84 (-42)))
myMin4 = TestCase (assertEqual "for (myMin (-42) 84)" (-42) (myMin (-42) 84))

myMax1 = TestCase (assertEqual "for (myMax 42 84)" (84) (myMax 42 84))
myMax2 = TestCase (assertEqual "for (myMax 84 42)" (84) (myMax 84 42))
myMax3 = TestCase (assertEqual "for (myMax 84 (-42))" (84) (myMax 84 (-42)))
myMax4 = TestCase (assertEqual "for (myMax (-42) 84)" (84) (myMax (-42) 84))

myTuple1 = TestCase (assertEqual "for (myTuple 42 84)" ((42, 84)) (myTuple 42 84))
myTuple2 = TestCase (assertEqual "for (myTuple 84 42)" ((84, 42)) (myTuple 84 42))
myTuple3 = TestCase (assertEqual "for (myTuple 84 (-42))" ((84, (-42))) (myTuple 84 (-42)))
myTuple4 = TestCase (assertEqual "for (myTuple (-42) 84)" (((-42), 84)) (myTuple (-42) 84))

myTruple1 = TestCase (assertEqual "for (myTruple 42 84 0)" ((42, 84, 0)) (myTruple 42 84 0))
myTruple2 = TestCase (assertEqual "for (myTruple 84 42 0)" ((42, 84, 0)) (myTruple 84 42 0))
myTruple3 = TestCase (assertEqual "for (myTruple 84 (-42) 0)" ((42, 84, 0)) (myTruple 84 (-42) 0))
myTruple4 = TestCase (assertEqual "for (myTruple (-42) 84 0)" ((42, 84, 0)) (myTruple (-42) 84 0))

myFst1 = TestCase (assertEqual "for (myFst (42, 84))" (42) (myFst (42, 84)))
myFst2 = TestCase (assertEqual "for (myFst ((-42), 84))" ((-42)) (myFst ((-42), 84)))

mySnd1 = TestCase (assertEqual "for (mySnd (42, 84))" (84) (mySnd (42, 84)))
mySnd2 = TestCase (assertEqual "for (mySnd (42, (-84))" ((-84)) (mySnd (42, (-84))))

mySwap1 = TestCase (assertEqual "for (mySwap (42, 84))" ((84, 42)) (mySwap (42, 84)))
mySwap2 = TestCase (assertEqual "for (mySwap (42, (-84)))" ((-84), 42) (mySwap (42, (-84))))

myHead1 = TestCase (assertEqual "for (myHead [42, 84])" (42) (myHead [42, 84]))
myHead2 = TestCase (assertEqual "for (myHead [42, (-84), 24])" (42) (myHead [42, (-84), 24]))
myHead3 = TestCase (assertEqual "for (myHead [42])" (42) (myHead [42]))

myTail1 = TestCase (assertEqual "for (myTail [42, 84])" ([84]) (myTail [42, 84]))
myTail2 = TestCase (assertEqual "for (myTail [42, (-84), 24])" ([(-84), 24]) (myTail [42, (-84), 24]))
myTail3 = TestCase (assertEqual "for (myTail [42])" ([]) (myTail [42]))

myLength1 = TestCase (assertEqual "for (myLength [42, 84])" (2) (myLength [42, 84]))
myLength2 = TestCase (assertEqual "for (myLength [42, (-84), 24])" (3) (myLength [42, (-84), 24]))
myLength3 = TestCase (assertEqual "for (myLength [42])" (1) (myLength [42]))

myNth1 = TestCase (assertEqual "for (myNth [42, 84] 0)" (42) (myNth [42, 84] 0))
myNth2 = TestCase (assertEqual "for (myNth [42, (-84), 24] 2)" (24) (myNth [42, (-84), 24] 2))
--myNth3 = TestCase (assertEqual "for (myNth [42] 4)" (0) (myNth [42] 4))

myTake1 = TestCase (assertEqual "for (myTake 1 [42, 84])" ([42]) (myTake 1 [42, 84]))
myTake2 = TestCase (assertEqual "for (myTake 2 [42, (-84), 24])" ([42, (-84)]) (myTake 2 [42, (-84), 24]))
myTake3 = TestCase (assertEqual "for (myTake 4 [42])" ([42]) (myTake 4 [42]))
myTake4 = TestCase (assertEqual "for (myTake 0 [42, 84])" ([]) (myTake 0 [42, 84]))

myDrop1 = TestCase (assertEqual "for (myDrop 1 [42, 84])" ([84]) (myDrop 1 [42, 84]))
myDrop2 = TestCase (assertEqual "for (myDrop 2 [42, (-84), 24])" ([24]) (myDrop 2 [42, (-84), 24]))
myDrop3 = TestCase (assertEqual "for (myDrop 4 [42])" ([]) (myDrop 4 [42]))
myDrop4 = TestCase (assertEqual "for (myDrop 0 [42, 84])" ([42, 84]) (myDrop 0 [42, 84]))

myAppend1 = TestCase (assertEqual "for (myAppend [1] [42, 84])" ([1, 42, 84]) (myAppend [1] [42, 84]))
myAppend2 = TestCase (assertEqual "for (myAppend [2, 5] [42, (-84), 24])" ([2, 5, 42, (-84), 24]) (myAppend [2, 5] [42, (-84), 24]))
myAppend3 = TestCase (assertEqual "for (myAppend [] [42])" ([42]) (myAppend [] [42]))
myAppend4 = TestCase (assertEqual "for (myAppend [42, 84] [])" ([42, 84]) (myAppend [42, 84] []))

myReverse1 = TestCase (assertEqual "for (myReverse [42, 84])" ([84, 42]) (myReverse [42, 84]))
myReverse2 = TestCase (assertEqual "for (myReverse [42, (-84), 24])" ([24, (-84), 42]) (myReverse [42, (-84), 24]))
myReverse3 = TestCase (assertEqual "for (myReverse [42])" ([42]) (myReverse [42]))
--myReverse4 = TestCase (assertEqual "for (myReverse [])" ([]) (myReverse []))