/**
 * ofxCsv_example is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2011-2012 Paul Vollmer
 *
 * ofxCsv_example is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxCsv_example is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxCsv_example; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.03.25
 * @version     0.1.2
 */



#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	shortcut.init("shortcuts.xml");
	
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	/*
	 * shortcut list.
	 * Here you can place your shortcut functions.
	 */
	if(key == shortcut.key[0]){
		cout << "key: " << shortcut.key[0] << ", description: " << shortcut.description[0] << endl;
		
		/* shortcut function here. */
	}
	else if(key == shortcut.key[1]) {
		/* shortcut function here. */
	}
	else if(key == shortcut.key[2]) {
		/* shortcut function here. */
	}
	else if(key == shortcut.key[3]) {
		/* shortcut function here. */
	}
	
	//shortcut.keyEvent(key);

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
