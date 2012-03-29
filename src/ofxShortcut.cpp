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
	void ofxShortcut::init(string file, string xmlShortcutTag){
		
		/*
		 * we load our settings file
		 * if it doesn't exist we can still make one
		 * Examlple from openFrameworks xmlSettingsExample
		 */
		if( xml.loadFile(file) ){
			cout << file << " loaded!" << endl;
		}else{
			cout << "unable to load " << file << " check data/ folder" << endl;
		}
		
		
		int totalShortcut = xml.getNumTags(xmlShortcutTag);
		cout << "totalShortcut: " << totalShortcut << endl;
		
		
		
		for(int i=0; i<10; i++){
			scut[i] = i;
			cout << scut[i] << endl;
		}
		
		
		#ifdef DEBUG
			cout << "[ofxShortcut] init()" << endl;
		#endif
		
	}
	
	/*
	 *
	 */
	void ofxShortcut::keyEvent(int key){
		
		#ifdef DEBUG
			cout << "[ofxShortcut] keyEvent key: " << key << endl;
		#endif
		
	}
	
}
