export default {
    props: [],
    data: function () {
      return {
        consoleDatas: "",
        pid: "",
        commande: "",
        status: "",
      };
    },
    mounted() {
      this.loadDatasConsole();
    },
    template: '\
    <div>\
      <h1>Console WEB Arduino</h1>\
    </div>\
    <div>\
        <textarea id="story" name="story" rows="25" cols="80">\
        </textarea>\
    </div>\
    <div>\
        <label id="labelPid" >Pid de session : </label>\
        <textarea id="pid" name="pid" rows="1" cols="10"> </textarea>\
        <br>\
        <label for="uname">Saisissez votre commande : </label>\
        <input id="commande" name="commande" cols="30">\
        <button @click="sendCommande">envoyer</button>\
        <br>\
        <label id="labelStatus" >Status de la commande : </label>\
        <textarea id="status" name="status" rows="1" cols="30"> </textarea>\
    </div>\
    ',
    methods: {
      envoyer() {
        let requete = this.$parent.httpServer + "/sendCommande?commande="+ this.commande + "&pid=" +this.pid
      },
      loadDatasConsole() {
        if (this.pid == ""){
          console.log("loadDataConsole => init pid")
          let requete = this.$parent.httpServer + "/initSession"
          fetch(requete).then(r => r.json()).then(response => {
            this.pid = response.pid;
            this.consoleDatas = "";
            this.commande = "";
            this.status = "";
          })
          .catch(error => {
            console.error(error);
            this.consigne = null;
          });       
        } else {
          console.log("loadDataConsole => chargement des données ...")
          let requete = this.$parent.httpServer + "/getDatasConsole?pid=" +this.pid
          fetch(requete).then(r => r.json()).then(response => {
            this.consoleDatas = response.consoleDatas;
            this.commande = "";
            this.status = response.status;
          })
          .catch(error => {
            console.error(error);
            this.consigne = null;
          });
        }
      },
    }
}