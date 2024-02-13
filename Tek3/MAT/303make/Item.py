class Item:
    def __init__(self, line):
        spl = line.split(":")
        self._filename = spl[0].strip()
        self._dependencies = []
        self.gradation = ""
        for dependence in spl[1].split():
            dep = dependence.strip()
            if not dependence:
                continue
            self._dependencies.append(dependence)

    def is_dependence(self, dep):
        return 1 if dep in self._dependencies else 0

    def __repr__(self):
        return self._filename + ": " + " ".join(self._dependencies)

    def __eq__(self, other):
        return other == self._filename
