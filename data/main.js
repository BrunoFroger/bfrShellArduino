const { createApp } = Vue;

// import Home from './home.js';
// import Console from '/console.js';

//var httpServer = 'http://localhost:3000'
//var httpServer = ''

const app = createApp({
    data() {
        return {
          currentDateTime: '',
          // page: 'console',
          board: null,
          consoleDatas: "",
          pid: undefined,
          commande: "",
          status: "",
          copyright: null,
          // httpServer: 'http://localhost:3000',
          // httpServer: 'http://localhost',
          httpServer: 'http://192.168.0.8:3000',
        }
    },
    mounted() {    
      this.loadDatasPiedPage();
      this.updateDateTime();
      this.loadDatasConsole();
      setInterval(this.updateDateTime, 1000);
    },
    template: '\
        <head> \
          <meta http-equiv="Access-Control-Allow-Origin" content="*"/> \
          <meta http-equiv="Access-Control-Allow-Methods" content="GET, POST, PUT"/> \
          <meta http-equiv="Access-Control-Allow-Headers" content="Content-Type"/> \
        </head> \
        <div class="entete">\
          <table>\
            <tr>\
              <td>{{currentDateTime}}</td>\
            </tr>\
          </table>\
        </div>\
        <div>\
          <h1>Console WEB Arduino</h1>\
        </div>\
        <div>\
            <textarea id="story" name="story" rows="25" cols="80">\
            </textarea>\
        </div>\
        <div>\
          <table>\
            <tr>\
              <td><label id="labelPid" >Pid de session : </label></td>\
              <td><textarea id="pid" name="pid" rows="1" cols="10"> </textarea></td>\
              <td></td>\
            </tr>\
            <tr>\
              <td><label for="uname">Saisissez votre commande : </label></td>\
              <td><input id="commande" name="commande" cols="30"></td>\
              <td><button @click="sendCommande">envoyer</button></td>\
            </tr>\
            <tr>\
              <td><label id="labelStatus" >Status de la commande : </label></td>\
              <td><textarea id="status" name="status" rows="1" cols="30"> </textarea></td>\
              <td></td>\
            </tr>\
          </table>\
        </div>\
        <!--div>\
          <component v-bind:is="page"></component>\
        </div-->\
        <div class="piedPage">\
          <p>Ce serveur est hébergé sur un arduino : {{board}}</p>\
          <i>Créé par : {{copyright}}</i>\
        </div>\
      ',
    methods: {
      updateDateTime() {
        const now = new Date();
        this.currentDateTime = now.toLocaleString();
      },
      sendCommande() {
        console.log("sendCommande => envoi de la commande " + this.commande)
        let requete = this.httpServer + "/sendCommande?commande=" + this.commande + "&pid=" +this.pid
          fetch(requete).then(r => r.json()).then(response => {
            this.consoleDatas = response.consoleDatas;
            this.commande = "";
            this.status = response.status;
          })
          .catch(error => {
            console.error(error);
            this.consigne = null;
          });
      },
      loadDatasConsole() {
        if (this.pid == undefined){
          console.log("loadDataConsole => init session")
          let requete = this.httpServer + "/initSession"
          
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
          let requete = this.httpServer + "/getDatasConsole?pid=" + this.pid
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
      loadDatasPiedPage() {
        let requete = this.httpServer + "/getDatasPiedPage"
        fetch(requete).then(r => r.json()).then(response => {
          this.board = response.board;
          this.copyright = response.copyright;
        })
        .catch(error => {
          console.error(error);
        });
      },
    }
});

// app.component('home', Home);
// app.component('console', Console);
app.mount('#app');
