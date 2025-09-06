package org.controller;

import org.utils.JsonLoader;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

public class Controller {
    //Current hashmap
    private HashMap<Character, ArrayList<String>> words;
    //All prevoius hashmaps to go back
    private ArrayList<HashMap<Character,ArrayList<String>>> baseToReset;
    private HashMap<Integer,ArrayList<Character>> numbers;
    //Position that we currently in with our hashmap, for excample we have hashmap build base on pos 3 of strings
    private int pos;
    //Count a position in array to show
    private ArrayList<String> listOfWords;
    //Iterator
    private int count;
    //Constructor
    public Controller(String filePath){
        HashMap<Character,ArrayList<String>> baseToReset = JsonLoader.loadJson(filePath);
        this.baseToReset = new ArrayList<>();
        this.words = baseToReset;
        this.listOfWords = new ArrayList<>();
        this.pos = 0;
        this.count = 0;

        ArrayList<Character> help = new ArrayList<>();
        numbers = new HashMap<>();

        help.add(0,'*');
        numbers.put(1,(ArrayList<Character>) help.clone());
        help.clear();

        help.add(0,'a');
        help.add(1,'b');
        help.add(2,'c');
        numbers.put(2,(ArrayList<Character>) help.clone());
        help.clear();

        help.add(0,'d');
        help.add(1,'e');
        help.add(2,'f');
        numbers.put(3,(ArrayList<Character>) help.clone());
        help.clear();

        help.add(0,'g');
        help.add(1,'h');
        help.add(2,'i');
        numbers.put(4,(ArrayList<Character>) help.clone());
        help.clear();

        help.add(0,'j');
        help.add(1,'k');
        help.add(2,'l');
        numbers.put(5,(ArrayList<Character>) help.clone());
        help.clear();

        help.add(0,'m');
        help.add(1,'n');
        help.add(2,'o');
        numbers.put(6,(ArrayList<Character>) help.clone());
        help.clear();

        help.add(0,'p');
        help.add(1,'q');
        help.add(2,'r');
        help.add(3,'s');
        numbers.put(7,(ArrayList<Character>) help.clone());
        help.clear();

        help.add(0,'t');
        help.add(1,'u');
        help.add(2,'v');
        numbers.put(8,(ArrayList<Character>) help.clone());
        help.clear();

        help.add(0,'w');
        help.add(1,'x');
        help.add(2,'y');
        help.add(3,'z');
        numbers.put(9,(ArrayList<Character>) help.clone());
        help.clear();
    }
    //print Words
    public void printWords(){
        System.out.println();
        System.out.println("Printing all keys with values for pos " + pos + " :\n");
        if(words.keySet().isEmpty()){
            System.out.println("Empty");
            return;
        }
        for(Character c : words.keySet()){
            System.out.println(c + ": " + words.get(c));
        }
    }
    //pressing key from numpad
    public void pressedKey(Integer number){
        pos++;
        count = 0;
        listOfWords.clear();
        this.baseToReset.add(words);
        HashMap<Character, ArrayList<String>> newMap = new HashMap<>();
        for(Character c : numbers.get(number)){
            ArrayList<String> list = words.getOrDefault(c,new ArrayList<String>());
            for(String s : list){
                listOfWords.add(s);
                if(pos < s.length()){
                    if(newMap.containsKey(s.charAt(pos))){
                        newMap.get(s.charAt(pos)).add(s);
                    }else{
                        newMap.put(s.charAt(pos),new ArrayList<String>());
                        newMap.get(s.charAt(pos)).add(s);
                    }
                }
            }
        }
        System.out.println(listOfWords);
        words = newMap;
    }
    //Going back to prevoius element on numpad
    public void previousEl(){
        if(pos != 0) {
            count = 0;
            this.words = baseToReset.get(pos - 1);
            listOfWords.clear();
            for(ArrayList<String> list : words.values()){
                for(String s : list){
                    listOfWords.add(s);
                }
            }
            baseToReset.remove(pos - 1);
            pos--;
        }

    }

    public HashMap<Character, ArrayList<String>> getWords() {
        return words;
    }
    public String nextWord(){
        if(count < listOfWords.size()){
            String s = listOfWords.get(count);
            count = (count+1) % listOfWords.size();
            return s;
        }
        return "No word in list";
    }
}
