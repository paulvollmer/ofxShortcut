/**
 * ofxShortcut_example is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxShortcut_example is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxShortcut_example is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxShortcut_example; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.03.30
 * @version     0.1.0
 */



#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	/* Load xml file and initialize shortcut class. */
	shortcut.init("shortcuts.xml");
	/* Optional you can customize the main-, id-, key- and description-tag of the xml file. */
	//shortcut.init("shortcuts.xml", "shortcut", "id", "key", "description");
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//cout << ofGetKeyPressed(97) << endl;
	
	/* Display a Shortcut List. */
	ofSetColor(0);
	shortcut.bitmapList(100, 100);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	
	cout << "key: " << key << endl;
	
	
	if(key == OF_KEY_ALT) {
		cout << "OF_KEY_ALT" << endl;
	}
	else if(key == OF_KEY_CTRL) {
		cout << "OF_KEY_CTRL" << endl;
	}
	else if(key == OF_KEY_SHIFT) {
		cout << "OF_KEY_SHIFT" << endl;
	}
	
	/* Shortcut List.
	 * Here you can place your shortcut functions at the
	 * specivic array position.
	 *
	 * Shortcut and description here. */
	if(shortcut.checkKey(key, 0)){
		cout << shortcut.description[0] << endl;
		/* Shortcut function and description here. */
		
	}
	
	/* Shortcut and description here. */
	else if(shortcut.checkKey(key, 1)) {
		cout << shortcut.description[1] << endl;
		/* Shortcut function and description here. */
		
	}
	
	/* Shortcut and description here. */
	else if(shortcut.checkKey(key, 2)) {
		cout << shortcut.description[2] << endl;
		/* Shortcut function and description here. */
	
	}
	
	/* Shortcut and description here. */
	else if(shortcut.checkKey(key, 3)) {
		cout << shortcut.description[3] << endl;
		/* Shortcut function and description here. */
	
	}
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}
