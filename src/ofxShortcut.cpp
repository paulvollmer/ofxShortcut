/**
 * ofxShortcut.cpp is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxShortcut.cpp is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxShortcut.cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxShortcut.cpp; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.03
 * @version     0.1.0b
 */


#include "ofxShortcut.h"



namespace wng {
	
	/**
	 * Constructor
	 */
	ofxShortcut::ofxShortcut(){
		
		filename = "shortcut.xml";
		
		#ifdef DEBUG
			cout << "[ofxShortcut] Constructor" << endl;
			cout << "              Default filename: " << filename << endl;
			cout << "              XML default Tags: main-tag = " << DEFAULT_XMLTAG_MAIN << endl;
			cout << "                                id-tag   = " << DEFAULT_XMLTAG_ID << endl;
			cout << "                                key-tag  = " << DEFAULT_XMLTAG_KEY << endl;
			cout << "                                desc-tag = " << DEFAULT_XMLTAG_DESC << endl;
		#endif
	}
	
	
	
	
	
	/**
	 * Initialize our shortcut xml file and parse it.
	 *
	 * @param file
	 *        Name of xml File.
	 * @param mainTag
	 *        The main xml tag.
	 * @param idTag
	 *        The ident xml tag.
	 * @param keyTag
	 *        The key xml tag.
	 * @param descriptionTag
	 *        The description xml tag.
	 */
	void ofxShortcut::init(string file, string mainTag, string idTag, string keyTag, string descriptionTag){
		
		/* we load our xml file
		 * Examlple from openFrameworks xmlSettingsExample */
		if( xml.loadFile(file) ){
			#ifdef DEBUG 
				cout << "[ofxShortcut] init()" << endl;
				cout << "              XML File <" << file << "> loaded!" << endl;
			#endif
			
			/* Save the filename to variable. */
			filename = file;
			
			/* Parse our loaded xml file and save key, description values to variable. */
			parseXml(mainTag, idTag, keyTag, descriptionTag);
		}else{
			#ifdef DEBUG
				cout << "[ofxShortcut] init()" << endl;
				cout << "              XML File unable to load <" << file << ">." << endl;
				cout << "              ofxShortcut start creating default shortcut settings file." << endl;
			#endif
			
			/* create an empty file. */
			//xml.addAttribute("wng", "attr1", 2, 0);
			xml.addTag(DEFAULT_XMLTAG_MAIN);
			xml.saveFile(filename);
			cout << "settings saved to xml!" << endl;
			
		}
		
	}
	
	
	
	/**
	 * Init description below.
	 */
	void ofxShortcut::init(string file){
		init(file, DEFAULT_XMLTAG_MAIN, DEFAULT_XMLTAG_ID, DEFAULT_XMLTAG_KEY, DEFAULT_XMLTAG_DESC);
	}
	
	void ofxShortcut::init(){
		init(filename, DEFAULT_XMLTAG_MAIN, DEFAULT_XMLTAG_ID, DEFAULT_XMLTAG_KEY, DEFAULT_XMLTAG_DESC);
	}
	
	
	
	
	
	/**
	 * Return a list of all shortcuts.
	 * For this we read our ident-, key-, desc-vector.
	 */
	string ofxShortcut::list(){
		
		string temp = "SHORTCUT LIST:\n";
		
		for(int i=0; i<id.size(); i++){
			char c = key[i];
			temp += "KEY: " + ofToString(c) + " (" + ofToString(key[i]) + ")   DESC: " + description[i] + "   ID: " + ofToString(id[i]) + "\n";
		}
		
		return temp;
	}
	
	
	
	
	
	/**
	 * checkKey
	 *
	 * @param mainTag
	 *        The main xml tag.
	 * @param mainTag
	 *        The main xml tag.
	 */
	bool ofxShortcut::checkKey(int k, int i){
		
		/* At first we watch if the vector (int i) we want to check really exist. 
		 * If we don't check this, we run into an "EXC_BAD_ACCESS" error.
		 * At next we can check the incomming key value and the key vector. */
		if(i < id.size() && k == key[i]){
			return true;
		} else {
			return false;
		}
		
	}
	
	
	
	
	
	/**
	 * Save our Xml Shortcut file.
	 *
	 * @param file
	 *        Name of xml File.
	 */
	void ofxShortcut::saveXml(string file){
	
		xml.saveFile(file);
		
		#ifdef DEBUG
			cout << "[ofxShortcut] saveXml() Save file " << file << " Ready!" << endl;
		#endif
		
	}
	
	void ofxShortcut::saveXml(){
		saveXml(filename);
	}
	
	
	
	
	
	/**
	 * parseXml to check how many shortcut tags exist.
	 * save all shortcut-keys, -description to array.
	 *
	 * @param mainTag
	 *        The main xml tag.
	 * @param idTag
	 *        The ident xml tag.
	 * @param keyTag
	 *        The key xml tag.
	 * @param descriptionTag
	 *        The description xml tag.
	 */
	void ofxShortcut::parseXml(string mainTag, string idTag, string keyTag, string descriptionTag){
		
		/* lets see how many <STROKE> </STROKE> tags there are in the xml file. */
		int totalShortcut = xml.getNumTags(mainTag);
		#ifdef DEBUG
			cout << "[ofxShortcut] parseXml() totalShortcut: " << totalShortcut << endl;
		#endif
		
		
		/* Check if a tag exist.
		 * Read all tags and save values to vector variable. */
		if(totalShortcut > 0){
			for(int i=0; i<totalShortcut; i++){
				
				/* save xml values to vector variable. */
				int    tempId   = xml.getValue(mainTag+":"+idTag,   i, i);
				int    tempKey  = xml.getValue(mainTag+":"+keyTag,  0x11120119, i);
				string tempDesc = xml.getValue(mainTag+":"+descriptionTag, "default shortcut description", i);
				
				/* save to shortcut vector */
				id.push_back(i);
				id[i] = tempId;				
				/* save to shortcut vector */
				key.push_back(i);
				key[i] = tempKey;
				/* save to shortcut vector */
				description.push_back("default");
				description[i] = tempDesc;
				
				#ifdef DEBUG
					cout << "[ofxShortcut] parseXml() [" << i << "] [id: " << id[i] << "] [key: " << key[i] << "] [description: " << description[i] << "]" <<  endl;
				#endif
				
			}
		}
		
	}
	
	
}
