/**
 * ofxShortcut.cpp is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2011-2012 Paul Vollmer
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
 * @modified    2012.03.29
 * @version     0.1.0
 */


#include "ofxShortcut.h"



namespace wng {
	
	/**
	 * Constructor
	 */
	ofxShortcut::ofxShortcut(){
		
		
		#ifdef DEBUG
			cout << "[ofxShortcut] Constructor" << endl;
		#endif
	}
	
	
	
	
	
	/**
	 * init
	 * Initialize our shortcut xml file and parse it.
	 *
	 * @param file
	 *        Name of xml File.
	 */
	void ofxShortcut::init(string file){
		
		/*
		 * we load our xml file
		 * Examlple from openFrameworks xmlSettingsExample
		 */
		if( xml.loadFile(file) ){
			#ifdef DEBUG 
				cout << "[ofxShortcut] init() XML File <" << file << "> loaded!" << endl;
			#endif
		}else{
			#ifdef DEBUG
				cout << "[ofxShortcut] init() XML File unable to load <" << file << ">." << endl;
				cout << "                     ofxShortcut start creating default shortcut settings file." << endl;
			#endif
			
			
			
			
			
			
			
			
			
			// create an empty file.
			/*xml.addTag("shortcut");
			xml.saveFile("mySettings.xml");
			cour << "settings saved to xml!" << endl;
			*/
			
			
			
			
			
			
		}
		
		
		/*
		 * Parse our loaded xml file and save key, description values to variable.
		 */
		parseXml("shortcut", "id", "key", "description");
		
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
	 * @param descTag
	 *        The description xml tag.
	 */
	void ofxShortcut::parseXml(string mainTag, string idTag, string keyTag, string descTag){
		
		/* 
		 * lets see how many <STROKE> </STROKE> tags there are in the xml file
		 */
		int totalShortcut = xml.getNumTags(mainTag);
		#ifdef DEBUG
			cout << "[ofxShortcut] parseXml() totalShortcut: " << totalShortcut << endl;
		#endif
		
		
		/*
		 * Check if a tag exist.
		 * Read all tags and save values to vector variable.
		 */
		if(totalShortcut > 0){
			for(int i=0; i<totalShortcut; i++){
				
				/*
				 * save xml values to vector variable.
				 */
				int    tempId   = xml.getValue(mainTag+":"+idTag,   i, i);
				int    tempKey  = xml.getValue(mainTag+":"+keyTag,  0x11120119, i);
				string tempDesc = xml.getValue(mainTag+":"+descTag, "default description", i);
				
				/* save to shortcut vector */
				ident.push_back(i);
				ident[i] = tempId;				
				/* save to shortcut vector */
				key.push_back(i);
				key[i] = tempKey;
				/* save to shortcut vector */
				description.push_back("default");
				description[i] = tempDesc;
				
				#ifdef DEBUG
					cout << "[ofxShortcut] parseXml() [" << i << "] [id: " << ident[i] << "] [key: " << key[i] << "] [description: " << description[i] << "]" <<  endl;
				#endif
			
			}
		}
		
	}
	
	
	
	
	
	void ofxShortcut::bitmapList(int x, int y){
		
		string temp = "SHORTCUT LIST:\n";
		
		for(int i=0; i<ident.size(); i++){
			char c = key[i];
			temp += "KEY: " + ofToString(c) + " (" + ofToString(key[i]) + ")   DESC: " + description[i] + "   ID: " + ofToString(ident[i]) + "\n";
		}
		
		ofDrawBitmapString(temp, x, y);
		
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
		
		if(k == key[i]){
			return true;
		} else {
			return false;
		}
		
	}
	
}
