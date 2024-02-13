import Data.Maybe (isJust)

data Item = Sword | Bow | MagicWand
                deriving (Eq)

data Mob = Mummy| Skeleton Item | Witch (Maybe Item)
                deriving (Eq)

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create [] = Nothing
create input = case input of
    "mummy" -> Just createMummy
    "doomed archer" -> Just createArcher
    "dead knight" -> Just createKnight
    "witch" -> Just createWitch
    "sorceress" -> Just createSorceress
    _ -> Nothing

equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip item (Witch item1) = Just (Witch (Just item))
equip item (Skeleton item2) = Just (Skeleton item)

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton item) = "skeleton holding a " ++ show item
    show (Witch Nothing) = "which"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just item)) = "witch holding a " ++ show item


class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool

instance HasItem Mob where
    getItem (Skeleton itemSkel) = Just itemSkel
    getItem (Witch itemWit) = itemWit
    getItem _ = Nothing
    hasItem (Skeleton itemSkel) = True
    hasItem (Witch itemWit) = isJust itemWit
    hasItem _ = False