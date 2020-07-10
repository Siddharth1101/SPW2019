class Trie:
    def __init__(self):
        self.root = {}

    def add(self,name,phone_number):
        """adds a name/number to the Trie"""
        node = self.root
        for char in name:
            if char not in node:
                node[char] = {}

            node = node[char]

        node["NUMBER"] = phone_number

    def find(self, prefix):
        """returns node after consuming given prefix"""
        node = self.root
        for char in prefix:
            if char not in node.keys():
                return None
            node = node[char]

        return node

    def list_contacts(self, prefix):
        sub_trie = self.find(prefix)
        _print(sub_trie, prefix)



def _print(subtrie, prefix):
    for key in subtrie.keys():
        if (key == "NUMBER"):
            print("{} : {}".format(prefix, subtrie[key]))
        else:
            _print(subtrie[key], prefix + key)


T = Trie()
T.add("Joe", 1234567868)
T.add("James", 4483455747)
T.add("Samantha", 4454443947)
T.add("name1",990271033); 
T.add("name2",948160469); 
T.add("name3",805067832); 
T.add("name4",734956637); 
T.add("name5",789274724); 
T.add("Abhinav",953533826); 
T.add("Anirudh",953573030); 
T.add("BV",890439569); 
T.add("Exculsec",949133705); 
T.add("Dell",948114818); 
T.add("DoST",944400805); 
T.add("Gaurav",951333138); 
T.add("Guhan",997245659); 
T.add("Hospital",442257833); 
T.add("Jobless",953516034); 
T.add("Keshav",961989327); 
T.add("Mainak",897182490); 
T.add("Milind",994031598); 
name=raw_input("Enter name: ")
T.list_contacts(name)