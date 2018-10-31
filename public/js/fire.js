var config = {
	apiKey: "replace with your key",
	authDomain: "replace with your authDomain",
	databaseURL: "replace with yourdatabase domain",
	projectId: "replace with your project id",
	storageBucket: "replace with your storagebucket",
	messagingSenderId: "replace with your messagesender"
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
