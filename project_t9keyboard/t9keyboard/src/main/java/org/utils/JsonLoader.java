package org.utils;

import org.json.JSONArray;
import org.json.JSONObject;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Objects;


public class JsonLoader {
    public static HashMap<Character,ArrayList<String>> loadJson(String filePath) {
        HashMap<Character,ArrayList<String>> words = new HashMap<Character, ArrayList<String>>();
        Character help = 'a';
        try {
            String content = new String(Files.readAllBytes(Paths.get(filePath)));
            JSONObject object = new JSONObject(content);
            JSONArray arr = (JSONArray) object.get("commonWords");
            ArrayList<String> toBePut = new ArrayList<>();
            for(Object obj : arr.toList()){
                String itWord = (String) obj;
                if(itWord.toLowerCase().charAt(0) == help){
                    toBePut.add(itWord);
                }else{
                    words.put(help,(ArrayList<String>) toBePut.clone());
                    toBePut.clear();
                    help = itWord.charAt(0);
                    toBePut.add(itWord);
                }
            }
        } catch (Exception e){
            e.printStackTrace();
        }
        return words;
    }
}
