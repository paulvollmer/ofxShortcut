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
	 * display
	 * Display our axis cross.
	 */
	void ofxShortcut::init(string file, string xmlTagKey){
		
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
				cout << "                     Check data/ folder" << endl;
			
			// TODO: create an empty file.
			
			#endif
		}
		
		
		/*
		 * Parse our loaded xml file and save key, description values to variable.
		 */
		parseXml("shortcut", "key", "description");
		
		
		
		/*for(int i=0; i<10; i++){
			scut[i] = i;
			cout << scut[i] << endl;
		}*/
		
		
		
		
		#ifdef DEBUG
			cout << "[ofxShortcut] init() Ready!" << endl;
		#endif
		
	}
	
	
	
	
	
	/*
	 * parseXml to check how many shortcut tags exist.
	 * save all shortcut-keys, -description to array.
	 *
	 *
	 */
	void ofxShortcut::parseXml(string mainTag, string keyTag, string descTag){
		
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
				
				int tempKey  = xml.getValue(mainTag+":"+keyTag,  0, i);
				string tempDesc = xml.getValue(mainTag+":"+descTag, "default description", i);
				
				/* save to shortcut vector */
				shortcut.push_back(i);
				shortcut[i] = tempKey;
				/* save to shortcut vector */
				description.push_back("ff");
				description[i] = tempDesc;
				
				#ifdef DEBUG
					cout << "[ofxShortcut] parseXml() [" << i << "] key: " << shortcut[i] << ", dsc: " << description[i] << endl;
				#endif
			
			}
		}
		
		#ifdef DEBUG
			cout << "[ofxShortcut] parseXml() Ready!" << endl;
		#endif
		
	}
	
	
	/*
	 * keyEvent
	 */
	void ofxShortcut::keyEvent(int key){
		
		#ifdef DEBUG
			cout << "[ofxShortcut] keyEvent key: " << key << endl;
		#endif
		
	}
	
}
