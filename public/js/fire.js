var config = {
	apiKey: "AIzaSyCuUyJX3hDtUVe3t87fzWKSZV9QkjJREyA",
	authDomain: "aegis-c7d5b.firebaseapp.com",
	databaseURL: "https://aegis-c7d5b.firebaseio.com",
	projectId: "aegis-c7d5b",
	storageBucket: "aegis-c7d5b.appspot.com",
	messagingSenderId: "703314974787"
};
firebase.initializeApp(config);
var database = firebase.database();
var leadsReflist = database.ref().child('data');
leadsReflist.on('child_changed',snap=>{
	const valuechanged=document.getElementById(snap.key);
	if(snap.val()=="alert"){
		window.alert("INTRUDER ALERT SOMEONE BREAKING INTO THE FRONT DOOR!!");
	}
	valuechanged.innerText=snap.val();
});
leadsReflist.on('child_added',snap=>{
	const valuechanged=document.getElementById(snap.key);

	valuechanged.innerText=snap.val();
});
