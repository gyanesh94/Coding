package Day9;

import java.util.HashMap;

class TrieNode {
	HashMap<Character, TrieNode> child;
	boolean eof;

	public TrieNode() {
		child = new HashMap<>();
		eof = false;
	}

	// for method 1
	public TrieNode(boolean eof) {
		child = new HashMap<>();
		this.eof = eof;
	}

	public boolean searchForChar(Character c) {
		for (Character tempC : child.keySet()) {
			if (tempC.equals(c)) {
				return true;
			}
		}
		return false;
	}

	public boolean searchForLastChar(Character c) {
		for (Character tempC : child.keySet()) {
			if (tempC.equals(c)) {
				TrieNode t = child.get(tempC);
				return t.eof;
			}
		}
		return false;
	}

	public void insertCharacter(Character c) {
		if (searchForChar(c)) {
			return;
		} else {
			TrieNode t = new TrieNode(false);
			child.put(c, t);
		}
	}

	public void insertLastCharacter(Character c) {
		if (searchForChar(c)) {
			TrieNode t = child.get(c);
			t.eof = true;
		} else {
			TrieNode t = new TrieNode(true);
			child.put(c, t);
		}
	}
}


//Method 2 Using class Sir method

class Trie {
	final TrieNode root;

	public Trie() {
		root = new TrieNode();
	}

	public void insert(String word) {
		insertString(word, root);
	}

	private void insertString(String word, TrieNode parent) {
		TrieNode current = parent;
		int len = word.length();

		for (int i = 0; i < len; i++) {
			char c = word.charAt(i);
			TrieNode node = current.child.get(c);
			if (node == null) {
				node = new TrieNode();
				current.child.put(c, node);
			}
			current = node;
		}
		current.eof = true;
	}

	public boolean search(String word) {
		return searchString(word, root);
	}

	private boolean searchString(String word, TrieNode parent) {
		TrieNode current = parent;
		int len = word.length();

		for (int i = 0; i < len; i++) {
			char c = word.charAt(i);
			TrieNode node = current.child.get(c);
			if (node == null) {
				return false;
			}
			current = node;
		}
		return current.eof;
	}

	public void delete(String word) {
		deleteString(word, root, 0);
	}

	private boolean deleteString(String word, TrieNode parent, int index) {
		if (index == word.length()) {
			if (parent == null) {
				return false;
			}

			parent.eof = false;
			return parent.child.size() == 0;
		}

		char ch = word.charAt(index);
		TrieNode node = parent.child.get(ch);
		if (node == null) {
			return false;
		}

		boolean deleteNodeAlso = deleteString(word, node, index + 1);
		if (deleteNodeAlso && !parent.eof) {
			parent.child.remove(ch);
			return parent.child.size() == 0;
		}
		return false;
	}
}

public class TrieUsingHash {

	public static void main(String[] args) {
		
		// Method 1
		TrieNode start = new TrieNode(false);
		String put;
		put = "hello";
		putString(start, put, 0);
		put = "hey";
		putString(start, put, 0);
		put = "abcd";
		putString(start, put, 0);

		System.out.println("Print words in Trie");
		printTrie(start, "");

		System.out.println();
		System.out.println("Search for words");
		System.out.println("abcd: " + searchString(start, "abcd", 0));
		System.out.println("hjd: " + searchString(start, "hjd", 0));
		System.out.println("ab: " + searchString(start, "ab", 0));
		System.out.println("hey: " + searchString(start, "hey", 0));

		deleteString(start, "hey", 0);

		System.out.println();
		System.out.println("Print words in Trie after deleting hey");
		printTrie(start, "");

		System.out.println();
		System.out.println("Search for words after deleting hey");
		System.out.println("abcd: " + searchString(start, "abcd", 0));
		System.out.println("hjd: " + searchString(start, "hjd", 0));
		System.out.println("ab: " + searchString(start, "ab", 0));
		System.out.println("hey: " + searchString(start, "hey", 0));

		
		// Method 2
		System.out.println();
		System.out.println();
		System.out.println("Using Method 2");
		Trie trieRoot = new Trie();
		trieRoot.insert("abcd");
		trieRoot.insert("a");
		trieRoot.insert("abc");
		trieRoot.insert("hello");
		trieRoot.insert("hey");

		System.out.println("Print words in Trie");
		printTrie(trieRoot.root, "");

		System.out.println();
		System.out.println("Search for words");
		System.out.println("abcd: " + trieRoot.search("abcd"));
		System.out.println("hjd: " + trieRoot.search("hjd"));
		System.out.println("ab: " + trieRoot.search("ab"));
		System.out.println("hey: " + trieRoot.search("hey"));

		trieRoot.delete("hey");
		trieRoot.delete("abcd");

		System.out.println();
		System.out.println("Print words in Trie after deleting hey");
		printTrie(trieRoot.root, "");

		System.out.println();
		System.out.println("Search for words after deleting hey");
		System.out.println("abcd: " + trieRoot.search("abcd"));
		System.out.println("abc: " + trieRoot.search("abc"));
		System.out.println("a: " + trieRoot.search("a"));
		System.out.println("hjd: " + trieRoot.search("hjd"));
		System.out.println("ab: " + trieRoot.search("ab"));
		System.out.println("hey: " + trieRoot.search("hey"));
	}

	public static void putString(TrieNode start, String string, int index) {
		int len = string.length();
		if (index == len - 1) {
			start.insertLastCharacter(string.charAt(index));
			return;
		}
		start.insertCharacter(string.charAt(index));
		putString(start.child.get(string.charAt(index)), string, index + 1);
	}

	public static boolean searchString(TrieNode start, String string, int index) {
		int len = string.length();
		if (index == len - 1) {
			return start.searchForLastChar(string.charAt(index));
		}
		if (start.searchForChar(string.charAt(index))) {
			return searchString(start.child.get(string.charAt(index)), string, index + 1);
		} else {
			return false;
		}
	}

	public static void printTrie(TrieNode start, String s) {
		for (Character tempC : start.child.keySet()) {
			String t = s + tempC;
			if (start.child.get(tempC).eof) {
				System.out.println(t);
			}
			printTrie(start.child.get(tempC), t);
		}
	}

	public static boolean deleteString(TrieNode start, String string, int index) {
		if (index == string.length()) {
			if (start == null) {
				return false;
			}

			start.eof = false;
			return start.child.size() == 0;
		}

		char ch = string.charAt(index);
		TrieNode node = start.child.get(ch);
		if (node == null) {
			return false;
		}

		boolean deleteNodeAlso = deleteString(node, string, index + 1);
		if (deleteNodeAlso && !start.eof) {
			start.child.remove(ch);
			return start.child.size() == 0;
		}
		return false;
	}
}
