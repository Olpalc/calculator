exports.id=521,exports.ids=[521],exports.modules={1629:(e,t,s)=>{s.r(t),s.d(t,{FocusWebviewProvider:()=>FocusWebviewProvider});var r=s(9496),i=s(5255),o=s(6631),n=s(8887),a=s(4155),u=s(8834),h=s(5367),c=s(8452),l=s(4092),p=s(4321),d=s(1529),f=s(2674),g=s(4794),b=s(4968),m=s(9529),R=s(5798);const w=new R.ke("focus/pr/openWorktree"),y=new R.ke("focus/pr/switchToBranch"),C=new R.jH("focus/state/didChange",!0),q=new R.jH("graph/subscription/didChange");class FocusWebviewProvider{constructor(e,t){this.container=e,this.host=t,this._bootstrapping=!0,this._pullRequests=[],this._issues=[],this._disposable=r.Disposable.from(this.container.subscription.onDidChange(this.onSubscriptionChanged,this),this.container.git.onDidChangeRepositories((()=>{this.host.refresh(!0)})))}dispose(){this._disposable.dispose()}registerCommands(){return[(0,m.xR)(i.Gh.RefreshFocus,(()=>this.host.refresh(!0)))]}onFocusChanged(e){e?setTimeout((()=>{(0,o.v)("gitlens:focus:focused",e)}),0):(0,o.v)("gitlens:focus:focused",e)}onMessageReceived(e){switch(e.method){case y.method:(0,R.mq)(y,e,(e=>this.onSwitchBranch(e)));break;case w.method:(0,R.mq)(w,e,(e=>this.onOpenWorktree(e)))}}findSearchedPullRequest(e){return this._pullRequests?.find((t=>t.pullRequest.id===e.id))}async getRemoteBranch(e){const t=e.pullRequest,s=e.repoAndRemote,i=s.repo.folder.uri,o=await s.repo.getMainRepository();if(null==o)return void r.window.showWarningMessage(`Unable to find main repository(${i.toString()}) for PR #${t.id}`);const n=t.refs.base.owner,u=r.Uri.parse(t.refs.base.url),h=t.refs.head.branch,c=r.Uri.parse(t.refs.head.url),l=c.toString(),[,d,f]=(0,g.Sk)(l);let b,m;if([b]=await o.getRemotes({filter:e=>e.matches(d,f)}),null!=b)m=`${b.name}/${h}`,await this.container.git.fetch(o.path,{remote:b.name});else{const e=await r.window.showInformationMessage(`Unable to find a remote for '${l}'. Would you like to add a new remote?`,{modal:!0},{title:"Yes"},{title:"No",isCloseAffordance:!0});if("Yes"!==e?.title)return;const s=t.refs.head.owner;if(await(0,a.IH)(o,s,l,{confirm:!1,fetch:!0,reveal:!1}),[b]=await o.getRemotes({filter:e=>e.url===l}),null==b)return;m=`${b.name}/${h}`;const i=t.refs.base.repo,p=`pr/${u.toString()===c.toString()?h:m}`;this.container.git.setConfig(o.path,`branch.${p}.github-pr-owner-number`,`${n}#${i}#${t.id}`)}return{remote:b,reference:(0,p.xB)(m,o.path,{refType:"branch",name:m,remote:!0})}}async onSwitchBranch({pullRequest:e}){const t=this.findSearchedPullRequest(e);if(null==t||t.isCurrentBranch)return Promise.resolve();if(null!=t.branch)return u.gu(t.branch.repoPath,t.branch);const s=await this.getRemoteBranch(t);return null==s?Promise.resolve():u.gu(s.remote.repoPath,s.reference)}async onOpenWorktree({pullRequest:e}){const t=this.findSearchedPullRequest(e);if(null==t?.repoAndRemote)return;const s=r.Uri.parse(e.refs.base.url),o=t.repoAndRemote.repo.folder;return(0,m.P0)(i.Gh.OpenOrCreateWorktreeForGHPR,{base:{repositoryCloneUrl:{repositoryName:e.refs.base.repo,owner:e.refs.base.owner,url:s}},githubRepository:{rootUri:o.uri},head:{ref:e.refs.head.branch,sha:e.refs.head.sha,repositoryCloneUrl:{repositoryName:e.refs.head.repo,owner:e.refs.head.owner,url:r.Uri.parse(e.refs.head.url)}},item:{number:parseInt(e.id,10)}})}async onSubscriptionChanged(e){if(e.etag===this._etagSubscription)return;this._etagSubscription=e.etag;const t=await this.container.git.access(n.x.Focus),{subscription:s,isPlus:r}=await this.getSubscription(t.subscription.current);return r&&this.notifyDidChangeState(),this.host.notify(q,{subscription:s,isPlus:r})}async getSubscription(e){const t=e??await this.container.subscription.getSubscription(!0);return{subscription:t,isPlus:![b.jc.Free,b.jc.FreePreviewTrialExpired,b.jc.FreePlusTrialExpired,b.jc.VerificationRequired].includes(t.state)}}async getState(e=!1){const{subscription:t,isPlus:s}=await this.getSubscription();if(!s)return{isPlus:s,subscription:t};const r=await this.getRichRepos(),i=r.filter((e=>e.isGitHub));const o=function(e){return e.filter((e=>e.isConnected&&e.isGitHub))}(i),n=o.length>0;if(e||!n)return{isPlus:s,subscription:t,repos:(n?o:i).map((e=>v(e)))};return{isPlus:s,subscription:t,pullRequests:(await this.getMyPullRequests(o)).map((e=>({pullRequest:(0,l.l1)(e.pullRequest),reasons:e.reasons,isCurrentBranch:e.isCurrentBranch??!1,isCurrentWorktree:e.isCurrentWorktree??!1,hasWorktree:e.hasWorktree??!1,hasLocalBranch:e.hasLocalBranch??!1}))),issues:(await this.getMyIssues(o)).map((e=>({issue:(0,c.y$)(e.issue),reasons:e.reasons}))),repos:o.map((e=>v(e)))}}async includeBootstrap(){if(this._bootstrapping){const e=await this.getState(!0);return e.isPlus&&this.notifyDidChangeState(),e}return this.getState()}async getRichRepos(e){if(null==this._repos||!0===e){const e=[],t=[];for(const s of this.container.git.openRepositories){const r=await s.getRichRemote();null==r||e.findIndex((e=>e.remote===r))>-1||(t.push(s.onDidChange(this.onRepositoryChanged,this)),e.push({repo:s,remote:r,isConnected:await r.provider.isConnected(),isGitHub:"GitHub"===r.provider.name}))}this._repositoryEventsDisposable&&(this._repositoryEventsDisposable.dispose(),this._repositoryEventsDisposable=void 0),this._repositoryEventsDisposable=r.Disposable.from(...t),this._repos=e}return this._repos}async onRepositoryChanged(e){e.changed(d.I6.RemoteProviders,d.du.Any)&&(await this.getRichRepos(!0),this.notifyDidChangeState())}async getMyPullRequests(e){const t=[];for(const s of e){const e=(await s.repo.getRemotes()).map((e=>e.name)),r=s.remote,i=await this.container.git.getMyPullRequests(r);if(null!=i)for(const r of i){if(0===r.reasons.length)continue;const i={...r,repoAndRemote:s,isCurrentWorktree:!1,isCurrentBranch:!1},o=e.map((e=>`${e}/${i.pullRequest.refs.head.branch}`)),n=await(0,f.K)(i.repoAndRemote.repo,i.pullRequest.refs.head.branch,o);i.hasWorktree=null!=n,i.isCurrentWorktree=!0===n?.opened;const a=await(0,h.fb)(s.repo,i.pullRequest.refs.head.branch,o);a&&(i.branch=a,i.hasLocalBranch=!0,i.isCurrentBranch=a.current),t.push(i)}}function s(e){let t=0;return e.reasons.includes("authored")?t+=1e3:e.reasons.includes("assigned")?t+=900:e.reasons.includes("review-requested")?t+=800:e.reasons.includes("mentioned")&&(t+=700),e.pullRequest.reviewDecision===l.pD.Approved?e.pullRequest.mergeableState===l.Cz.Mergeable?t+=100:e.pullRequest.mergeableState===l.Cz.Conflicting?t+=90:t+=80:e.pullRequest.reviewDecision===l.pD.ChangesRequested&&(t+=70),t}return this._pullRequests=t.sort(((e,t)=>{const r=s(e),i=s(t);return r===i?e.pullRequest.date.getTime()-t.pullRequest.date.getTime():(i??0)-(r??0)})),this._pullRequests}async getMyIssues(e){const t=[];for(const{remote:s}of e){const e=await this.container.git.getMyIssues(s);null!=e&&t.push(...e.filter((e=>e.reasons.length>0)))}return this._issues=t.sort(((e,t)=>t.issue.updatedDate.getTime()-e.issue.updatedDate.getTime())),this._issues}async notifyDidChangeState(){if(!this.host.visible)return;const e=await this.getState();this._bootstrapping=!1,this.host.notify(C,{state:e})}}function v(e){return{repo:e.repo.path,isGitHub:e.isGitHub,isConnected:e.isConnected}}}};